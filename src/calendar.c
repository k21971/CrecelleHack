/* NetHack 3.7	calendar.c	$NHDT-Date: 1706213796 2024/01/25 20:16:36 $  $NHDT-Branch: NetHack-3.7 $:$NHDT-Revision: 1.116 $ */
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/*-Copyright (c) Michael Allison, 2007. */
/* Copyright (c) Robert Patrick Rankin, 1991                      */
/* NetHack may be freely redistributed.  See license for details. */

#include "hack.h"

/*
 * Time routines
 *
 * The time is used for:
 *  - seed for rand()
 *  - year on tombstone and yyyymmdd in record file
 *  - phase of the moon (various monsters react to NEW_MOON or FULL_MOON)
 *  - night and midnight (the undead are dangerous at midnight)
 *  - determination of what files are "very old"
 */

/* TIME_type: type of the argument to time(); we actually use &(time_t);
   you might need to define either or both of these to 'long *' in *conf.h */
#ifndef TIME_type
#define TIME_type time_t *
#endif
#ifndef LOCALTIME_type
#define LOCALTIME_type time_t *
#endif

staticfn struct tm *getlt(void);
staticfn void weather_effects(void);

static struct weather dungeon_precips[] = {
    { "Calm", 0, WTHM_ALL_PRECIPS, 300, 575 },
    { "Drizzle", WTH_DRIZZLE, WTHM_ALL_PRECIPS, 200, 200 },
    { "Rain", WTH_RAIN, WTHM_ALL_PRECIPS, 100, 200 },
    { "Downburst", WTH_DOWNBURST, WTHM_ALL_PRECIPS, 50, 10 },
    { "Acid Rain", WTH_ACIDRAIN, WTHM_ALL_PRECIPS, 50, 5 },
    { "Hail", WTH_HAIL, 0, 20, 10 },
};

static struct weather dungeon_winds[] = {
    { "Calm", 0, WTHM_ALL_WINDS, 250, 400 },
    { "Breeze", WTH_BREEZE, WTH_GUST, 300, 250 },
    { "Wind", WTH_WIND, 0, 150, 200 },
    { "Gust", WTH_GUST, WTH_BREEZE, 150, 100 },
    { "Tornado", WTH_TORNADO | WTH_GUST, 0, 100, 50 }
};

static struct weather harassment_precip[] = {
    { "Acidstorm", 0, WTH_ACIDRAIN, 100, 350 },
    { "Firestorm", 0, WTH_FIRERAIN, 100, 350 },
    { "Hailstorm", 0, WTH_HAIL, 100, 300 }
};

time_t
getnow(void)
{
    time_t datetime = 0;

    (void) time((TIME_type) &datetime);
    return datetime;
}

staticfn struct tm *
getlt(void)
{
    time_t date = getnow();

    return localtime((LOCALTIME_type) &date);
}

int
getyear(void)
{
    return (1900 + getlt()->tm_year);
}


long
yyyymmdd(time_t date)
{
    long datenum;
    struct tm *lt;

    if (date == 0)
        lt = getlt();
    else
        lt = localtime((LOCALTIME_type) &date);

    /* just in case somebody's localtime supplies (year % 100)
       rather than the expected (year - 1900) */
    if (lt->tm_year < 70)
        datenum = (long) lt->tm_year + 2000L;
    else
        datenum = (long) lt->tm_year + 1900L;
    /* yyyy --> yyyymm */
    datenum = datenum * 100L + (long) (lt->tm_mon + 1);
    /* yyyymm --> yyyymmdd */
    datenum = datenum * 100L + (long) lt->tm_mday;
    return datenum;
}

long
hhmmss(time_t date)
{
    long timenum;
    struct tm *lt;

    if (date == 0)
        lt = getlt();
    else
        lt = localtime((LOCALTIME_type) &date);

    timenum = lt->tm_hour * 10000L + lt->tm_min * 100L + lt->tm_sec;
    return timenum;
}

char *
yyyymmddhhmmss(time_t date)
{
    long datenum;
    static char datestr[15];
    struct tm *lt;

    if (date == 0)
        lt = getlt();
    else
        lt = localtime((LOCALTIME_type) &date);

    /* just in case somebody's localtime supplies (year % 100)
       rather than the expected (year - 1900) */
    if (lt->tm_year < 70)
        datenum = (long) lt->tm_year + 2000L;
    else
        datenum = (long) lt->tm_year + 1900L;
    Snprintf(datestr, sizeof datestr, "%04ld%02d%02d%02d%02d%02d",
             datenum, lt->tm_mon + 1,
             lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
    //debugpline1("yyyymmddhhmmss() produced date string %s", datestr);
    return datestr;
}

time_t
time_from_yyyymmddhhmmss(char *buf)
{
    int k;
    time_t timeresult = (time_t) 0;
    struct tm t, *lt;
    char *d, *p, y[5], mo[3], md[3], h[3], mi[3], s[3];

    if (buf && strlen(buf) == 14) {
        d = buf;
        p = y; /* year */
        for (k = 0; k < 4; ++k)
            *p++ = *d++;
        *p = '\0';
        p = mo; /* month */
        for (k = 0; k < 2; ++k)
            *p++ = *d++;
        *p = '\0';
        p = md; /* day */
        for (k = 0; k < 2; ++k)
            *p++ = *d++;
        *p = '\0';
        p = h; /* hour */
        for (k = 0; k < 2; ++k)
            *p++ = *d++;
        *p = '\0';
        p = mi; /* minutes */
        for (k = 0; k < 2; ++k)
            *p++ = *d++;
        *p = '\0';
        p = s; /* seconds */
        for (k = 0; k < 2; ++k)
            *p++ = *d++;
        *p = '\0';
        lt = getlt();
        if (lt) {
            t = *lt;
            t.tm_year = atoi(y) - 1900;
            t.tm_mon = atoi(mo) - 1;
            t.tm_mday = atoi(md);
            t.tm_hour = atoi(h);
            t.tm_min = atoi(mi);
            t.tm_sec = atoi(s);
            timeresult = mktime(&t);
        }
        if (timeresult == (time_t) -1)
            ;
#if 0
TODO: set_debugpline1, debugpline1 -> function pointer
            debugpline1("time_from_yyyymmddhhmmss(%s) would have returned -1",
                        buf ? buf : "");
#endif
        else
            return timeresult;
    }
    return (time_t) 0;
}

/*
 * moon period = 29.53058 days ~= 30, year = 365.2422 days
 * days moon phase advances on first day of year compared to preceding year
 *      = 365.2422 - 12*29.53058 ~= 11
 * years in Metonic cycle (time until same phases fall on the same days of
 *      the month) = 18.6 ~= 19
 * moon phase on first day of year (epact) ~= (11*(year%19) + 29) % 30
 *      (29 as initial condition)
 * current phase in days = first day phase + days elapsed in year
 * 6 moons ~= 177 days
 * 177 ~= 8 reported phases * 22
 * + 11/22 for rounding
 */
int
phase_of_the_moon(void) /* 0-7, with 0: new, 4: full */
{
    struct tm *lt = getlt();
    int epact, diy, goldn;

    diy = lt->tm_yday;
    goldn = (lt->tm_year % 19) + 1;
    epact = (11 * goldn + 18) % 30;
    if ((epact == 25 && goldn > 11) || epact == 24)
        epact++;

    return ((((((diy + epact) * 6) + 11) % 177) / 22) & 7);
}

boolean
friday_13th(void)
{
    struct tm *lt = getlt();

    /* tm_wday (day of week; 0==Sunday) == 5 => Friday */
    return (boolean) (lt->tm_wday == 5 && lt->tm_mday == 13);
}

int
rt_night(void)
{
    int hour = getlt()->tm_hour;

    return (hour < 6 || hour > 21);
}

int
night(void)
{
    return (u.uenvirons.tod == TOD_EARLYNIGHT
            || u.uenvirons.tod == TOD_LATENIGHT);
}

int
rt_midnight(void)
{
    return (getlt()->tm_hour == 0);
}

int
midnight(void)
{
    return ((u.uenvirons.tod == TOD_EARLYNIGHT 
                && u.uenvirons.tod_cnt <= 100)
            || (u.uenvirons.tod == TOD_LATENIGHT 
                && u.uenvirons.tod_cnt >= TOD_QUARTER - 100));
}

int
midday(void)
{
    return ((u.uenvirons.tod == TOD_MORNING
                && u.uenvirons.tod_cnt <= 100)
            || (u.uenvirons.tod == TOD_EVENING
                    && u.uenvirons.tod_cnt >= TOD_QUARTER - 100));
}

int
calc_dt_vis(void)
{
    int amt;
    if (night()) return u.nv_range;
    amt = (u.uenvirons.tod == TOD_MORNING) 
            ? (TOD_QUARTER - u.uenvirons.tod_cnt) : u.uenvirons.tod_cnt;
    if (u.uenvirons.curr_weather & WTH_DRIZZLE) amt -= 100;
    if (u.uenvirons.curr_weather & (WTH_RAIN | WTH_ACIDRAIN)) {
         amt -= 200;
    }
    if (u.uenvirons.curr_weather & WTH_ASHES) amt -= 300;
    return max(1, 3 + (amt / 100));
}

void
roll_precip(void)
{
    int i;
    int x = 0;
    int total_prob = 0;
    for (i = 0; i < SIZE(dungeon_precips); i++) {
        x += dungeon_precips[i].prob;
    }
    x = rn2(x);
    for (i = 0; i < SIZE(dungeon_precips); i++) {
        total_prob += dungeon_precips[i].prob;
        if (x < total_prob) {
            u.uenvirons.inc_precip = &dungeon_precips[i];
            return;
        }
    }
    panic("Like tears in the rain... (%d %d)", x, total_prob);
}

void
roll_wind(void)
{
    int i;
    int x = 0;
    int total_prob = 0;
    for (i = 0; i < SIZE(dungeon_winds); i++) {
        x += dungeon_winds[i].prob;
    }
    x = rn2(x);
    for (i = 0; i < SIZE(dungeon_winds); i++) {
        total_prob += dungeon_winds[i].prob;
        if (x < total_prob) {
            u.uenvirons.inc_precip = &dungeon_winds[i];
            return;
        }
    }
    panic("A black wind blows through you... (%d %d)", x, total_prob);
}

void
doenvirons(void)
{
    u.uenvirons.tod_cnt--;
    u.uenvirons.precip_cnt--;
    u.uenvirons.wind_cnt--;
    u.uenvirons.dt_vis = calc_dt_vis();
    if (!u.uenvirons.tod_cnt) {
        u.uenvirons.tod_cnt = TOD_QUARTER;
        u.uenvirons.tod += 1;
        if (u.uenvirons.tod > TOD_LATENIGHT) u.uenvirons.tod = TOD_MORNING;
        timechange_message(FALSE);
    }
    if (!u.uenvirons.precip_cnt) {
        weatherchange_message(TRUE);
        if (!u.uenvirons.inc_precip)
            u.uenvirons.inc_precip = &dungeon_precips[0];
        u.uenvirons.curr_weather &= ~u.uenvirons.inc_precip->overwrite;
        u.uenvirons.curr_weather |= u.uenvirons.inc_precip->def;
        u.uenvirons.precip_cnt = rn1(u.uenvirons.inc_precip->timeout, u.uenvirons.inc_precip->timeout);
        roll_precip();
    }
    if (!u.uenvirons.wind_cnt) {
        weatherchange_message(FALSE);
        if (INC_WIND(WTH_TORNADO)) {
            (void) makemon(&mons[PM_TORNADO], 0, 0, NO_MM_FLAGS);
        }
        if (!u.uenvirons.inc_wind)
            u.uenvirons.inc_wind = &dungeon_winds[0];
        u.uenvirons.curr_weather &= ~u.uenvirons.inc_wind->overwrite;
        u.uenvirons.curr_weather |= u.uenvirons.inc_wind->def;
        u.uenvirons.wind_cnt = rn1(u.uenvirons.inc_wind->timeout, u.uenvirons.inc_wind->timeout);
        roll_wind();
    }
    weather_effects();
}

staticfn void
weather_effects(void)
{
    int x, y;
    if (has_no_tod_cycles(&u.uz)) return;
    /* Rain and acid rain */
    if (IS_RAINING) {
        if (rn2(CURR_WEATHER(WTH_DRIZZLE) ? 2 
                : CURR_WEATHER(WTH_DOWNBURST) ? 8 : 4)) {
            x = rn2(COLNO);
            y = rn2(ROWNO);
            floor_alchemy(x, y, CURR_WEATHER(WTH_ACIDRAIN) ? POT_ACID 
                                                          : POT_WATER, 0);
        }
    }
    /* Ash fall */
    if (CURR_WEATHER(WTH_ASHES)) {
        x = rn2(COLNO);
        y = rn2(ROWNO);
        add_coating(x, y, COAT_ASHES, 0);
    }
    /* Hailstones */
    if (CURR_WEATHER(WTH_HAIL)) {
        if (!rn2(4)) {
            You("are pounded by hailstones!");
            losehp(Maybe_Half_Phys(d(1, 4)), "pounded by hailstones",
                NO_KILLER_PREFIX);
        }
    }
    /* Rain of Fire */
    if (CURR_WEATHER(WTH_FIRERAIN)) {
        x = rn2(COLNO);
        y = rn2(ROWNO);
        if (isok(x, y)) {
            clear_heros_fault(create_bonfire(x, y, 1, 1));
        }
    }
    /* Tornados */
    if (CURR_WEATHER(WTH_TORNADO) && !rn2(150)) {
        (void) makemon(&mons[PM_TORNADO], 0, 0, NO_MM_FLAGS);
    }
}

const char *
tod_string(void)
{
    if (midnight()) return "Midnight";
    if (night()) return "Night";
    if (midday()) return "Midday";
    if (u.uenvirons.tod == TOD_MORNING) return "Morning";
    return "Evening";
}

void
weatherchange_message(boolean rain)
{
    if (has_no_tod_cycles(&u.uz)) return;
    if (rain) {
        /* Don't do messages if the weather is continuing */
        if (!u.uenvirons.inc_precip || (u.uenvirons.curr_weather & u.uenvirons.inc_precip->def))
            return;
        /* Actually do messages */
        if (INC_PRECIP(WTH_ACIDRAIN)) {
            if (IS_RAINING) {
                pline("The rain suddenly begins to burn your %s!", body_part(NOSE));
                stop_occupation();
            } else {
                pline("It's raining acid!");
                stop_occupation();
            }
        } else if (INC_PRECIP(WTH_HAIL)) {
            pline("It starts to hail!");
            stop_occupation();
        } else if (INC_PRECIP(WTH_FIRERAIN)) {
            pline("Fire falls from the sky!");
            stop_occupation();
        } else if (INC_PRECIP(WTH_DRIZZLE)) {
            if (!IS_RAINING)
                pline("It starts drizzling.");
            else
                pline("The rain lessens.");
        } else if (INC_PRECIP(WTH_ASHES)) {
            pline("Flakes of ash begin falling from the sky.");
        } else if (INC_PRECIP(WTHM_RAINS) && !IS_RAINING) {
            pline("It starts to rain.");
        } else if (!INC_PRECIP(WTHM_RAINS) && IS_RAINING) {
            pline("It stops raining.");
        }
    } else {
        if (!u.uenvirons.inc_wind || (u.uenvirons.curr_weather & u.uenvirons.inc_wind->def))
            return;
        if (INC_WIND(WTH_WIND) && !CURR_WEATHER(WTHM_WINDY)) {
            pline("The wind picks up.");
        }
        if (!INC_WIND(WTHM_WINDY) && CURR_WEATHER(WTHM_WINDY)) {
            pline("The wind dies down.");
        }
        if (INC_WIND(WTH_TORNADO) && !Blind) {
            pline("You see a funnel cloud touch down!");
            stop_occupation();
        }
    }
}

void
timechange_message(boolean new_game)
{
    if (has_no_tod_cycles(&u.uz)) return;
    if (u.uenvirons.tod == TOD_MORNING) {
        if (Blind)
            pline("You feel the warmth of the sun on your %s.", body_part(FACE));
        pline("%s%s", new_game ? "" 
                             : Hallucination
                                ? "The morning sun has vanquished the horrible night."
                                : "The sun crests the edge of the dungeon.",
                     Hallucination ? "" : " It is morning.");
    } else if (u.uenvirons.tod == TOD_EVENING) {
        if (Blind) pline("The sun beats down atop your %s.", body_part(HEAD));
        else pline("The sun passes the sky's zenith.");
    } else if (u.uenvirons.tod == TOD_EARLYNIGHT) {
        if (Blind) pline("The warmth of the sun disappears.");
        else pline("The sun has set.");
        /* Moon messages */
        if (flags.moonphase == FULL_MOON && !new_game) {
            pline("The full moon rises overhead.");
        } else if (flags.moonphase == NEW_MOON && Hallucination && !new_game) {
            pline("There is no moon.");
        }
    } else {
        pline("It is midnight.");
    }
}

void
harassment_weather(void)
{
    int x = rn2(1000);
    int total_prob = 0;
    for (int i = 0; i < SIZE(harassment_precip); i++) {
        total_prob += harassment_precip[i].prob;
        if (x < total_prob) {
            u.uenvirons.inc_precip = &harassment_precip[i];
            break;
        }
    }
    u.uenvirons.precip_cnt = 1;
}

/* calendar.c */

