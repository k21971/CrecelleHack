/* NetHack 3.7	mextra.h	$NHDT-Date: 1720717969 2024/07/11 17:12:49 $  $NHDT-Branch: NetHack-3.7 $:$NHDT-Revision: 1.40 $ */
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/*-Copyright (c) Michael Allison, 2006. */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef MEXTRA_H
#define MEXTRA_H

#ifndef ALIGN_H
#include "align.h"
#endif

/*
 *  Adding new mextra structures:
 *
 *       1. Add the structure definition and any required macros in this
 *          file above the mextra struct.
 *       2. Add a pointer to your new struct to the mextra struct in this
 *          file.
 *       3. Add a referencing macro at bottom of this file after the mextra
 *          struct (see MGIVENNAME, EGD, EPRI, ESHK, EMIN, or EDOG for
 *          examples).
 *       4. If your new field isn't a pointer and requires a non-zero value
 *          on initialization, add code to init_mextra() in src/makemon.c
 *       5. Create a newXX(mtmp) function and possibly a free_XX(mtmp)
 *          function in an appropriate new or existing source file and add
 *          a prototype for it to include/extern.h.
 *
 *              void newXX(struct monst *);
 *              void free_XX(struct monst *);
 *
 *              void
 *              newXX(mtmp)
 *              struct monst *mtmp;
 *              {
 *                  if (!mtmp->mextra)
 *                      mtmp->mextra = newmextra();
 *                  if (!XX(mtmp)) {
 *                      XX(mtmp) = (struct XX *) alloc(sizeof (struct XX));
 *                      (void) memset((genericptr_t) XX(mtmp),
 *                                    0, sizeof (struct XX));
 *                  }
 *              }
 *
 *       6. Consider adding a new makemon flag MM_XX flag to include/hack.h
 *          and a corresponding change to makemon() if you require your
 *          structure to be added at monster creation time.  Initialize your
 *          struct after a successful return from makemon().
 *
 *              src/makemon.c:  if (mmflags & MM_XX) newXX(mtmp);
 *              your new code:  mon = makemon(&mons[mnum], x, y, MM_XX);
 *
 *       7. Adjust size_monst() in src/wizcmds.c appropriately.
 *       8. Adjust dealloc_mextra() in src/mon.c to clean up
 *          properly during monst deallocation.
 *       9. Adjust copy_mextra() in src/mon.c to make duplicate
 *          copies of your struct or data on another monst struct.
 *      10. Adjust restmon() in src/restore.c to deal with your
 *          struct or data during a restore.
 *      11. Adjust savemon() in src/save.c to deal with your
 *          struct or data during a save.
 */

/***
 **     formerly vault.h -- vault guard extension
 */
#define FCSIZ (ROWNO + COLNO)
#define GD_EATGOLD 0x01
#define GD_DESTROYGOLD 0x02

struct fakecorridor {
    coordxy fx, fy;
    schar ftyp; /* from struct rm's typ */
    uchar flags; /* also from struct rm; an unsigned 5-bit field there */
};

struct egd {
    unsigned parentmid;   /* make clobber-detection possible */
    int fcbeg, fcend;     /* fcend: first unused pos */
    int vroom;            /* room number of the vault */
    coordxy gdx, gdy;     /* goal of guard's walk */
    coordxy ogx, ogy;     /* guard's last position */
    d_level gdlevel;      /* level (& dungeon) guard was created in */
    xint8 warncnt;        /* number of warnings to follow */
    xint8 dropgoldcnt;    /* number of demands to drop gold */
    Bitfield(gddone, 1);  /* true iff guard has released player */
    Bitfield(witness, 2); /* the guard saw you do something */
    Bitfield(unused, 5);
    struct fakecorridor fakecorr[FCSIZ];
};

/***
 **     formerly epri.h -- temple priest extension
 */
struct epri {
    unsigned parentmid;   /* make clobber-detection possible */
    aligntyp shralign; /* alignment of priest's shrine */
    schar shroom;      /* index in rooms */
    coord shrpos;      /* position of shrine */
    d_level shrlevel;  /* level (& dungeon) of shrine */
    long intone_time,  /* used to limit verbosity  +*/
        enter_time,    /*+ of temple entry messages */
        hostile_time,  /* forbidding feeling */
        peaceful_time; /* sense of peace */
};
/* note: roaming priests (no shrine) switch from ispriest to isminion
   (and emin extension) */

/***
 **     formerly eshk.h -- shopkeeper extension
 */
#define REPAIR_DELAY 5 /* minimum delay between shop damage & repair */
#define BILLSZ 200

struct bill_x {
    unsigned bo_id;
    boolean useup;
    long price; /* price per unit */
    long bquan; /* amount used up */
};

struct eshk {
    unsigned parentmid;   /* make clobber-detection possible */
    long robbed;          /* amount stolen by most recent customer */
    long credit;          /* amount credited to customer */
    long debit;           /* amount of debt for using unpaid items */
    long loan;            /* shop-gold picked (part of debit) */
    int shoptype;         /* the value of svr.rooms[shoproom].rtype */
    schar shoproom;       /* index in svr.rooms; set by inshop() */
    schar unused;         /* to force alignment for stupid compilers */
    boolean following;    /* following customer since he owes us sth */
    boolean surcharge;    /* angry shk inflates prices */
    boolean dismiss_kops; /* pacified shk sends kops away */
    coord shk;            /* usual position shopkeeper */
    coord shd;            /* position shop door */
    d_level shoplevel;    /* level (& dungeon) of his shop */
    int billct;           /* no. of entries of bill[] in use */
    struct bill_x bill[BILLSZ];
    struct bill_x *bill_p;  /* &(ESHK(shkp)->bill[0]) */
    long break_seq;         /* hero_seq value at time of object breakage */
    boolean seq_peaceful;   /* shkp->mpeaceful at start of break_seq */
    int visitct;            /* nr of visits by most recent customer */
    char customer[PL_NSIZ]; /* most recent customer */
    char shknam[PL_NSIZ];
};

/***
 **     formerly emin.h -- minion extension
 */
struct emin {
    unsigned parentmid;   /* make clobber-detection possible */
    aligntyp min_align; /* alignment of minion */
    boolean renegade;   /* hostile co-aligned priest or Angel */
};

/***
 **     formerly edog.h -- pet extension
 */
/*      various types of pet food, the lower the value, the better liked */
enum dogfood_types {
    DOGFOOD = 0,
    CADAVER = 1,
    ACCFOOD = 2,
    MANFOOD = 3,
    APPORT  = 4,
    POISON  = 5,
    UNDEF   = 6,
    TABU    = 7
};

struct edog {
    unsigned parentmid;       /* make clobber-detection possible */
    long droptime;            /* moment dog dropped object */
    unsigned dropdist;        /* dist of dropped obj from @ */
    int apport;               /* amount of training */
    long whistletime;         /* last time he whistled */
    long hungrytime;          /* will get hungry at this time */
    coord ogoal;              /* previous goal location */
    int abuse;                /* track abuses to this pet */
    int revivals;             /* count pet deaths */
    int mhpmax_penalty;       /* while starving, points reduced */
    Bitfield(killed_by_u, 1); /* you attempted to kill him */
};

/***
 **     extension tracking a player's remnant monster (ghost, mummy etc.)
 */
struct ebones {
    unsigned parentmid;     /* make clobber-detection possible */
    uchar role;             /* index into roles[] */
    uchar race;             /* index into races[] */
    align oldalign;         /* character alignment */
    uchar deathlevel;       /* level when dying (m_lev may differ) */
    schar luck;             /* luck when dying */
    short mnum;             /* monster type */
    Bitfield(female, 1);    /* was female */
    Bitfield(demigod, 1);   /* had killed wiz or invoked */
    Bitfield(crowned, 1);   /* had been crowned */
};

/***
 **     mextra.h -- collection of all monster extensions
 */
struct mextra {
    char *mgivenname;
    struct egd *egd;
    struct epri *epri;
    struct eshk *eshk;
    struct emin *emin;
    struct edog *edog;
    struct ebones *ebones;
    int mcorpsenm; /* obj->corpsenm for mimic posing as statue or corpse,
                    * obj->spe (fruit index) for one posing as a slime mold,
                    * or an alignment mask for one posing as an altar */
};

#define MGIVENNAME(mon) ((mon)->mextra->mgivenname)
#define EGD(mon) ((mon)->mextra->egd)
#define EPRI(mon) ((mon)->mextra->epri)
#define ESHK(mon) ((mon)->mextra->eshk)
#define EMIN(mon) ((mon)->mextra->emin)
#define EDOG(mon) ((mon)->mextra->edog)
#define EBONES(mon) ((mon)->mextra->ebones)
#define MCORPSENM(mon) ((mon)->mextra->mcorpsenm)

#define has_mgivenname(mon) ((mon)->mextra && MGIVENNAME(mon))
#define has_egd(mon)   ((mon)->mextra && EGD(mon))
#define has_epri(mon)  ((mon)->mextra && EPRI(mon))
#define has_eshk(mon)  ((mon)->mextra && ESHK(mon))
#define has_emin(mon)  ((mon)->mextra && EMIN(mon))
#define has_edog(mon)  ((mon)->mextra && EDOG(mon))
#define has_ebones(mon) ((mon)->mextra && EBONES(mon))
#define has_mcorpsenm(mon) ((mon)->mextra && MCORPSENM(mon) != NON_PM)

#endif /* MEXTRA_H */
