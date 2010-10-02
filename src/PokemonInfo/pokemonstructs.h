#ifndef POKEMONSTRUCTS_H
#define POKEMONSTRUCTS_H

#include <QtGui>
#include <QDataStream>
#include "../Utilities/functions.h"

class QDomElement;

namespace Version
{
    enum {
        Platinum = 14,
        SoulSilver = 15,
        HeartGold = 16
    };

    enum {
        LastGen = 4,
        NumberOfGens = 5
    };

    static const int avatarSize[] = {
        0,
        0,
        64,
        80,
        96
    };
}

namespace Pokemon
{
    enum Gender
    {
        Neutral,
        Male,
        Female
    };

    enum Status {
        /* Koed = -2,*/
        /* Levitated = -1,*/
        Fine = 0,
        Paralysed = 1,
        Asleep = 2,
        Frozen = 3,
        Burnt = 4,
        Poisoned = 5,
        Confused = 6,
        Attracted = 7,
        Wrapped = 8,
        Nightmared = 9,
        Tormented = 12,
        Disabled = 13,
        Drowsy = 14,
        HealBlocked = 15,
        Sleuthed = 17,
        Seeded = 18,
        Embargoed = 19,
        Requiemed = 20,
        Rooted = 21,
        Koed = 31
    };

    /*
     Old status

    enum Status
    {
        Koed = -2,
        Fine=0,
        Paralysed=1,
        Burnt=2,
        Frozen=3,
        Asleep=4,
        Poisoned=5,
        DeeplyPoisoned=6
    };

    */

    enum StatusKind
    {
        NoKind = 0,
        SimpleKind = 1,
        TurnKind = 2,
        AttractKind = 3,
        WrapKind = 4
    };

    /* For simplicity issues we keep the same order as in Gender. You can assume it'll stay
   that way for next versions.

   That allows you to do PokemonInfo::Picture(pokenum, (Gender)GenderAvail(pokenum)) */

    enum GenderAvail
    {
        NeutralAvail,
        MaleAvail,
        FemaleAvail,
        MaleAndFemaleAvail
    };

    enum Type
    {
        Normal = 0,
        Fighting,
        Flying,
        Poison,
        Ground,
        Rock,
        Bug,
        Ghost,
        Steel,
        Fire,
        Water,
        Grass,
        Electric,
        Psychic,
        Ice,
        Dragon,
        Dark,
        Curse = 17
    };

    enum Nature
    {
        Hardy = 0,
        Lonely,
        Brave,
        Adamant,
        Naughty,
        Bold,
        Docile,
        Relaxed,
        Impish,
        Lax,
        Timid,
        Hasty,
        Serious,
        Jolly,
        Naive,
        Modest,
        Mild,
        Quiet,
        Bashful,
        Rash,
        Calm,
        Gentle,
        Sassy,
        Careful,
        Quirky = 24
    };

    enum Name
    {
        NoPoke,
        Bulbasaur,
        Ivysaur,
        Venusaur,
        Charmander,
        Charmeleon,
        Charizard,
        Squirtle,
        Wartortle,
        Blastoise,
        Caterpie,
        Metapod,
        Butterfree,
        Weedle,
        Kakuna,
        Beedrill,
        Pidgey,
        Pidgeotto,
        Pidgeot,
        Rattata,
        Raticate,
        Spearow,
        Fearow,
        Ekans,
        Arbok,
        Pikachu,
        Raichu,
        Sandshrew,
        Sandslash,
        Nidoran_F,
        Nidorina,
        Nidoqueen,
        Nidoran_M,
        Nidorino,
        Nidoking,
        Clefairy,
        Clefable,
        Vulpix,
        Ninetales,
        Jigglypuff,
        Wigglytuff,
        Zubat,
        Golbat,
        Oddish,
        Gloom,
        Vileplume,
        Paras,
        Parasect,
        Venonat,
        Venomoth,
        Diglett,
        Dugtrio,
        Meowth,
        Persian,
        Psyduck,
        Golduck,
        Mankey,
        Primeape,
        Growlithe,
        Arcanine,
        Poliwag,
        Poliwhirl,
        Poliwrath,
        Abra,
        Kadabra,
        Alakazam,
        Machop,
        Machoke,
        Machamp,
        Bellsprout,
        Weepinbell,
        Victreebel,
        Tentacool,
        Tentacruel,
        Geodude,
        Graveler,
        Golem,
        Ponyta,
        Rapidash,
        Slowpoke,
        Slowbro,
        Magnemite,
        Magneton,
        Farfetchd,
        Doduo,
        Dodrio,
        Seel,
        Dewgong,
        Grimer,
        Muk,
        Shellder,
        Cloyster,
        Gastly,
        Haunter,
        Gengar,
        Onix,
        Drowzee,
        Hypno,
        Krabby,
        Kingler,
        Voltorb,
        Electrode,
        Exeggcute,
        Exeggutor,
        Cubone,
        Marowak,
        Hitmonlee,
        Hitmonchan,
        Lickitung,
        Koffing,
        Weezing,
        Rhyhorn,
        Rhydon,
        Chansey,
        Tangela,
        Kangaskhan,
        Horsea,
        Seadra,
        Goldeen,
        Seaking,
        Staryu,
        Starmie,
        MrMime,
        Scyther,
        Jynx,
        Electabuzz,
        Magmar,
        Pinsir,
        Tauros,
        Magikarp,
        Gyarados,
        Lapras,
        Ditto,
        Eevee,
        Vaporeon,
        Jolteon,
        Flareon,
        Porygon,
        Omanyte,
        Omastar,
        Kabuto,
        Kabutops,
        Aerodactyl,
        Snorlax,
        Articuno,
        Zapdos,
        Moltres,
        Dratini,
        Dragonair,
        Dragonite,
        Mewtwo,
        Mew,
        Chikorita,
        Bayleef,
        Meganium,
        Cyndaquil,
        Quilava,
        Typhlosion,
        Totodile,
        Croconaw,
        Feraligatr,
        Sentret,
        Furret,
        Hoothoot,
        Noctowl,
        Ledyba,
        Ledian,
        Spinarak,
        Ariados,
        Crobat,
        Chinchou,
        Lanturn,
        Pichu,
        Cleffa,
        Igglybuff,
        Togepi,
        Togetic,
        Natu,
        Xatu,
        Mareep,
        Flaaffy,
        Ampharos,
        Bellossom,
        Marill,
        Azumarill,
        Sudowoodo,
        Politoed,
        Hoppip,
        Skiploom,
        Jumpluff,
        Aipom,
        Sunkern,
        Sunflora,
        Yanma,
        Wooper,
        Quagsire,
        Espeon,
        Umbreon,
        Murkrow,
        Slowking,
        Misdreavus,
        Unown,
        Wobbuffet,
        Girafarig,
        Pineco,
        Forretress,
        Dunsparce,
        Gligar,
        Steelix,
        Snubbull,
        Granbull,
        Qwilfish,
        Scizor,
        Shuckle,
        Heracross,
        Sneasel,
        Teddiursa,
        Ursaring,
        Slugma,
        Magcargo,
        Swinub,
        Piloswine,
        Corsola,
        Remoraid,
        Octillery,
        Delibird,
        Mantine,
        Skarmory,
        Houndour,
        Houndoom,
        Kingdra,
        Phanpy,
        Donphan,
        Porygon2,
        Stantler,
        Smeargle,
        Tyrogue,
        Hitmontop,
        Smoochum,
        Elekid,
        Magby,
        Miltank,
        Blissey,
        Raikou,
        Entei,
        Suicune,
        Larvitar,
        Pupitar,
        Tyranitar,
        Lugia,
        Ho_Oh,
        Celebi,
        Treecko,
        Grovyle,
        Sceptile,
        Torchic,
        Combusken,
        Blaziken,
        Mudkip,
        Marshtomp,
        Swampert,
        Poochyena,
        Mightyena,
        Zigzagoon,
        Linoone,
        Wurmple,
        Silcoon,
        Beautifly,
        Cascoon,
        Dustox,
        Lotad,
        Lombre,
        Ludicolo,
        Seedot,
        Nuzleaf,
        Shiftry,
        Taillow,
        Swellow,
        Wingull,
        Pelipper,
        Ralts,
        Kirlia,
        Gardevoir,
        Surskit,
        Masquerain,
        Shroomish,
        Breloom,
        Slakoth,
        Vigoroth,
        Slaking,
        Nincada,
        Ninjask,
        Shedinja,
        Whismur,
        Loudred,
        Exploud,
        Makuhita,
        Hariyama,
        Azurill,
        Nosepass,
        Skitty,
        Delcatty,
        Sableye,
        Mawile,
        Aron,
        Lairon,
        Aggron,
        Meditite,
        Medicham,
        Electrike,
        Manectric,
        Plusle,
        Minun,
        Volbeat,
        Illumise,
        Roselia,
        Gulpin,
        Swalot,
        Carvanha,
        Sharpedo,
        Wailmer,
        Wailord,
        Numel,
        Camerupt,
        Torkoal,
        Spoink,
        Grumpig,
        Spinda,
        Trapinch,
        Vibrava,
        Flygon,
        Cacnea,
        Cacturne,
        Swablu,
        Altaria,
        Zangoose,
        Seviper,
        Lunatone,
        Solrock,
        Barboach,
        Whiscash,
        Corphish,
        Crawdaunt,
        Baltoy,
        Claydol,
        Lileep,
        Cradily,
        Anorith,
        Armaldo,
        Feebas,
        Milotic,
        Castform,
        Kecleon,
        Shuppet,
        Banette,
        Duskull,
        Dusclops,
        Tropius,
        Chimecho,
        Absol,
        Wynaut,
        Snorunt,
        Glalie,
        Spheal,
        Sealeo,
        Walrein,
        Clamperl,
        Huntail,
        Gorebyss,
        Relicanth,
        Luvdisc,
        Bagon,
        Shelgon,
        Salamence,
        Beldum,
        Metang,
        Metagross,
        Regirock,
        Regice,
        Registeel,
        Latias,
        Latios,
        Kyogre,
        Groudon,
        Rayquaza,
        Jirachi,
        Deoxys,
        Turtwig,
        Grotle,
        Torterra,
        Chimchar,
        Monferno,
        Infernape,
        Piplup,
        Prinplup,
        Empoleon,
        Starly,
        Staravia,
        Staraptor,
        Bidoof,
        Bibarel,
        Kricketot,
        Kricketune,
        Shinx,
        Luxio,
        Luxray,
        Budew,
        Roserade,
        Cranidos,
        Rampardos,
        Shieldon,
        Bastiodon,
        Burmy,
        Wormadam,
        Mothim,
        Combee,
        Vespiquen,
        Pachirisu,
        Buizel,
        Floatzel,
        Cherubi,
        Cherrim,
        Shellos,
        Gastrodon,
        Ambipom,
        Drifloon,
        Drifblim,
        Buneary,
        Lopunny,
        Mismagius,
        Honchkrow,
        Glameow,
        Purugly,
        Chingling,
        Stunky,
        Skuntank,
        Bronzor,
        Bronzong,
        Bonsly,
        MimeJr,
        Happiny,
        Chatot,
        Spiritomb,
        Gible,
        Gabite,
        Garchomp,
        Munchlax,
        Riolu,
        Lucario,
        Hippopotas,
        Hippowdon,
        Skorupi,
        Drapion,
        Croagunk,
        Toxicroak,
        Carnivine,
        Finneon,
        Lumineon,
        Mantyke,
        Snover,
        Abomasnow,
        Weavile,
        Magnezone,
        Lickilicky,
        Rhyperior,
        Tangrowth,
        Electivire,
        Magmortar,
        Togekiss,
        Yanmega,
        Leafeon,
        Glaceon,
        Gliscor,
        Mamoswine,
        Porygon_Z,
        Gallade,
        Probopass,
        Dusknoir,
        Froslass,
        Rotom,
        Uxie,
        Mesprit,
        Azelf,
        Dialga,
        Palkia,
        Heatran,
        Regigigas,
        Giratina,
        Cresselia,
        Phione,
        Manaphy,
        Darkrai,
        Shaymin,
        Arceus,
        Victini,
        Tsutarja,
        Janobii,
        Jaroda,
        Pokabu,
        Chaobuu,
        Enbuoo,
        Mijumaru,
        Futachimaru,
        Daikenki,
        Minezumi,
        Miruhoggu,
        Yooterii,
        Haderia,
        Muurando,
        Choroneko,
        Leperasudu,
        Yanappu,
        Yanakki,
        Boappu,
        Baokki,
        Hiyappu,
        Hiyakki,
        Munna,
        Musharna,
        Mamepato,
        Hatoopoo,
        Kenhorou,
        Shimama,
        Zeburaika,
        Dangoro,
        Gantoru,
        Gigaiasu,
        Koromori,
        Kokoromori,
        Moguryuu,
        Doryuuzu,
        Tabunne,
        Dokkora,
        Dotekkotsu,
        Roopushin,
        Otamaru,
        Gamagaru,
        Gamageroge,
        Nageki,
        Dageki,
        Kurumiru,
        Kurumayu,
        Hahakurimo,
        Futsude,
        Hoiiga,
        Pendoraa,
        Monmon,
        Erufuun,
        Churine,
        Doreida,
        Basurao,
        Meguroko,
        Warubiru,
        Warubiaru,
        Darumakka,
        Hihidaruma,
        Marakacchi,
        Ishizumai,
        Iwaparesu,
        Zuruggu,
        Zuruzukin,
        Shinpora,
        Desumasu,
        Desukan,
        Purotooga,
        Abagoora,
        Aaken,
        Aakeosu,
        Yabakuron,
        Dasutodasu,
        Zorua,
        Zoroark,
        Chillarmy,
        Chirachiino,
        Gochimu,
        Gochimiru,
        Gochiruzeru,
        Yuniran,
        Daburan,
        Rankurusu,
        Koaruhii,
        Swanna,
        Banipucchi,
        Baniricchi,
        Baibanira,
        Shikijika,
        Mebukijka,
        Emonga,
        Kaburuchi,
        Shubarugo,
        Tamagetake,
        Morobareru,
        Pururiru,
        Burunkeru,
        Mamanbou,
        Bachuru,
        Denchura,
        Tesshiido,
        Nattorei,
        Gear,
        Gigear,
        Gigigear,
        Shibishirasu,
        Shibibiiru,
        Shibirudon,
        Riguree,
        Oobemu,
        Hitomoshi,
        Ranpuraa,
        Shanderaa,
        Kibago,
        Onondo,
        Ononokusu,
        Kumashun,
        Tsunbeaa,
        Furiijio,
        Chobomaki,
        Agirudaa,
        Maggyo,
        Kojofuu,
        Kojondo,
        Kurimugan,
        Gobitto,
        Goruggo,
        Komatana,
        Kirikizan,
        Baffuron,
        Washibon,
        Wargle,
        Baruchai,
        Barujiina,
        Kuitaran,
        Aianto,
        Monozu,
        Jiheddo,
        Sazando,
        Meraruba,
        Urugamosu,
        Kobaruon,
        Terakion,
        Birijion,
        Torunerosu,
        Borutorosu,
        Reshiram,
        Zekrom,
        Randorosu,
        Kyuremu,
        Kerudio,
        Meloia,
        Insekuta,
        // Base forms end here.
        Rotom_C = Rotom + (1 << 16),
        Rotom_H = Rotom + (2 << 16),
        Rotom_F = Rotom + (3 << 16),
        Rotom_W = Rotom + (4 << 16),
        Rotom_S = Rotom + (5 << 16),
        Deoxys_A = Deoxys + (1 << 16),
        Deoxys_D = Deoxys + (2 << 16),
        Deoxys_S = Deoxys + (3 << 16),
        Wormadam_G = Wormadam + (1 << 16),
        Wormadam_S = Wormadam + (2 << 16),
        Giratina_O = Giratina + (1 << 16),
        Shaymin_S = Shaymin + (1 << 16),
        Meloia_S = Meloia + (1 << 16)
    };
    class uniqueId
    {
    public:
        quint16 pokenum;
        quint8 subnum;
        uniqueId() : pokenum(0), subnum(0) {}
        uniqueId(int num, int subnum) : pokenum(num), subnum(subnum) {}
        uniqueId(const uniqueId &id) { pokenum = id.pokenum; subnum = id.subnum; }
        uniqueId(quint32 pokeRef) {
              subnum = pokeRef >> 16;
              pokenum = pokeRef & 0xFFFF;
        }
        bool operator == (const uniqueId &other) const {
            return (pokenum == other.pokenum) && (subnum == other.subnum);
        }
        bool operator != (const uniqueId &other) const {
            return (pokenum != other.pokenum) || (subnum != other.subnum);
        }
        bool operator < (const uniqueId &other) const {
            return (pokenum < other.pokenum) || ((pokenum == other.pokenum) && (subnum < other.subnum));
        }
        bool operator > (const uniqueId &other) const {
            return (pokenum > other.pokenum) || ((pokenum == other.pokenum) && (subnum > other.subnum));
        }
        QString toString() const;
        QString toLine(const QString &data) const;
        quint32 toPokeRef() const;
        // Separates pokenum:subnum:1-letter-options data from
        // the other part of a string.
        // 'data' will be modified to hold extracted data.
        // 'remaining' will be modified to hold remaining part.
        // Will return true if everything is fine. And false otherwise.
        static bool extract(const QString &raw, uniqueId &id, QString &info, QString *options = NULL);
        // Extracts short data in a "pokenum data_text" form.
        static bool extract_short(const QString &from, quint16 &pokenum, QString &remaining);
    };
}

namespace Move
{
    enum Category
    {
        Other,
        Physical,
        Special
    };

    /*
     Old:

    enum Category
    {
        Physical,
        Special,
        Other
    };

    */

    enum Flags
    {
        ContactFlag = 1,
        ChargeFlag = 2,
        RechargeFlag = 4,
        ProtectableFlag = 8,
        MagicCoatableFlag = 16,
        SnatchableFlag = 32,
        MemorableFlag = 64,
        PunchFlag = 128,
        SoundFlag = 256,
        FlyingFlag = 512,
        UnthawingFlag = 1024,
        PulsingFlag = 2048,
        HealingFlag = 4096,
        MischievousFlag = 8192
    };

    enum Target
    {
        ChosenTarget = 0,
        PartnerOrUser = 1,
        Partner = 2,
        MeFirstTarget = 3,
        AllButSelf = 4,
        Opponents = 5,
        TeamParty = 6,
        User = 7,
        All = 8,
        RandomTarget = 9,
        Field = 10,
        OpposingTeam = 11,
        TeamSide = 12,
        IndeterminateTarget = 13
    };

    /*
     Old:
    enum Target
    {
	None = -1,
	User,
	ChosenTarget,
	RandomTarget,
	Opponents,
	All,
        AllButSelf,
        PartnerOrUser
    };
    */

    enum Classification
    {
        StandardMove = 0,
        StatusInducingMove = 1,
        StatChangingMove = 2,
        HealingMove = 3,
        OffensiveStatusInducingMove = 4,
        StatAndStatusMove = 5,
        OffensiveStatChangingMove = 6,
        OffensiveSelfStatChangingMove = 7,
        AbsorbingMove = 8,
        OHKOMove = 9,
        FieldMove = 10,
        TeamZoneMove = 11,
        RoaringMove = 12,
        SpecialMove = 13
    };

    enum Name
    {
        NoMove,
        Pound,
        KarateChop,
        DoubleSlap,
        CometPunch,
        MegaPunch,
        PayDay,
        FirePunch,
        IcePunch,
        ThunderPunch,
        Scratch,
        ViceGrip,
        Guillotine,
        RazorWind,
        SwordsDance,
        Cut,
        Gust,
        WingAttack,
        Whirlwind,
        Fly,
        Bind,
        Slam,
        VineWhip,
        Stomp,
        DoubleKick,
        MegaKick,
        JumpKick,
        RollingKick,
        Sand_Attack,
        Headbutt,
        HornAttack,
        FuryAttack,
        HornDrill,
        Tackle,
        BodySlam,
        Wrap,
        TakeDown,
        Thrash,
        Double_Edge,
        TailWhip,
        PoisonSting,
        Twineedle,
        PinMissile,
        Leer,
        Bite,
        Growl,
        Roar,
        Sing,
        Supersonic,
        SonicBoom,
        Disable,
        Acid,
        Ember,
        Flamethrower,
        Mist,
        WaterGun,
        HydroPump,
        Surf,
        IceBeam,
        Blizzard,
        Psybeam,
        BubbleBeam,
        AuroraBeam,
        HyperBeam,
        Peck,
        DrillPeck,
        Submission,
        LowKick,
        Counter,
        SeismicToss,
        Strength,
        Absorb,
        MegaDrain,
        LeechSeed,
        Growth,
        RazorLeaf,
        SolarBeam,
        PoisonPowder,
        StunSpore,
        SleepPowder,
        PetalDance,
        StringShot,
        DragonRage,
        FireSpin,
        ThunderShock,
        Thunderbolt,
        ThunderWave,
        Thunder,
        RockThrow,
        Earthquake,
        Fissure,
        Dig,
        Toxic,
        Confusion,
        Psychic,
        Hypnosis,
        Meditate,
        Agility,
        QuickAttack,
        Rage,
        Teleport,
        NightShade,
        Mimic,
        Screech,
        DoubleTeam,
        Recover,
        Harden,
        Minimize,
        SmokeScreen,
        ConfuseRay,
        Withdraw,
        DefenseCurl,
        Barrier,
        LightScreen,
        Haze,
        Reflect,
        FocusEnergy,
        Bide,
        Metronome,
        MirrorMove,
        Selfdestruct,
        EggBomb,
        Lick,
        Smog,
        Sludge,
        BoneClub,
        FireBlast,
        Waterfall,
        Clamp,
        Swift,
        SkullBash,
        SpikeCannon,
        Constrict,
        Amnesia,
        Kinesis,
        Softboiled,
        HiJumpKick,
        Glare,
        DreamEater,
        PoisonGas,
        Barrage,
        LeechLife,
        LovelyKiss,
        SkyAttack,
        Transform,
        Bubble,
        DizzyPunch,
        Spore,
        Flash,
        Psywave,
        Splash,
        AcidArmor,
        Crabhammer,
        Explosion,
        FurySwipes,
        Bonemerang,
        Rest,
        RockSlide,
        HyperFang,
        Sharpen,
        Conversion,
        TriAttack,
        SuperFang,
        Slash,
        Substitute,
        Struggle,
        Sketch,
        TripleKick,
        Thief,
        SpiderWeb,
        MindReader,
        Nightmare,
        FlameWheel,
        Snore,
        Curse,
        Flail,
        Conversion2,
        Aeroblast,
        CottonSpore,
        Reversal,
        Spite,
        PowderSnow,
        Protect,
        MachPunch,
        ScaryFace,
        FaintAttack,
        SweetKiss,
        BellyDrum,
        SludgeBomb,
        Mud_Slap,
        Octazooka,
        Spikes,
        ZapCannon,
        Foresight,
        DestinyBond,
        PerishSong,
        IcyWind,
        Detect,
        BoneRush,
        Lock_On,
        Outrage,
        Sandstorm,
        GigaDrain,
        Endure,
        Charm,
        Rollout,
        FalseSwipe,
        Swagger,
        MilkDrink,
        Spark,
        FuryCutter,
        SteelWing,
        MeanLook,
        Attract,
        SleepTalk,
        HealBell,
        Return,
        Present,
        Frustration,
        Safeguard,
        PainSplit,
        SacredFire,
        Magnitude,
        DynamicPunch,
        Megahorn,
        DragonBreath,
        BatonPass,
        Encore,
        Pursuit,
        RapidSpin,
        SweetScent,
        IronTail,
        MetalClaw,
        VitalThrow,
        MorningSun,
        Synthesis,
        Moonlight,
        HiddenPower,
        CrossChop,
        Twister,
        RainDance,
        SunnyDay,
        Crunch,
        MirrorCoat,
        PsychUp,
        ExtremeSpeed,
        AncientPower,
        ShadowBall,
        FutureSight,
        RockSmash,
        Whirlpool,
        BeatUp,
        FakeOut,
        Uproar,
        Stockpile,
        SpitUp,
        Swallow,
        HeatWave,
        Hail,
        Torment,
        Flatter,
        Will_O_Wisp,
        Memento,
        Facade,
        FocusPunch,
        SmellingSalt,
        FollowMe,
        NaturePower,
        Charge,
        Taunt,
        HelpingHand,
        Trick,
        RolePlay,
        Wish,
        Assist,
        Ingrain,
        Superpower,
        MagicCoat,
        Recycle,
        Revenge,
        BrickBreak,
        Yawn,
        KnockOff,
        Endeavor,
        Eruption,
        SkillSwap,
        Imprison,
        Refresh,
        Grudge,
        Snatch,
        SecretPower,
        Dive,
        ArmThrust,
        Camouflage,
        TailGlow,
        LusterPurge,
        MistBall,
        FeatherDance,
        TeeterDance,
        BlazeKick,
        MudSport,
        IceBall,
        NeedleArm,
        SlackOff,
        HyperVoice,
        PoisonFang,
        CrushClaw,
        BlastBurn,
        HydroCannon,
        MeteorMash,
        Astonish,
        WeatherBall,
        Aromatherapy,
        FakeTears,
        AirCutter,
        Overheat,
        OdorSleuth,
        RockTomb,
        SilverWind,
        MetalSound,
        GrassWhistle,
        Tickle,
        CosmicPower,
        WaterSpout,
        SignalBeam,
        ShadowPunch,
        Extrasensory,
        SkyUppercut,
        SandTomb,
        SheerCold,
        MuddyWater,
        BulletSeed,
        AerialAce,
        IcicleSpear,
        IronDefense,
        Block,
        Howl,
        DragonClaw,
        FrenzyPlant,
        BulkUp,
        Bounce,
        MudShot,
        PoisonTail,
        Covet,
        VoltTackle,
        MagicalLeaf,
        WaterSport,
        CalmMind,
        LeafBlade,
        DragonDance,
        RockBlast,
        ShockWave,
        WaterPulse,
        DoomDesire,
        PsychoBoost,
        Roost,
        Gravity,
        MiracleEye,
        Wake_UpSlap,
        HammerArm,
        GyroBall,
        HealingWish,
        Brine,
        NaturalGift,
        Feint,
        Pluck,
        Tailwind,
        Acupressure,
        MetalBurst,
        U_turn,
        CloseCombat,
        Payback,
        Assurance,
        Embargo,
        Fling,
        PsychoShift,
        TrumpCard,
        HealBlock,
        WringOut,
        PowerTrick,
        GastroAcid,
        LuckyChant,
        MeFirst,
        Copycat,
        PowerSwap,
        GuardSwap,
        Punishment,
        LastResort,
        WorrySeed,
        SuckerPunch,
        ToxicSpikes,
        HeartSwap,
        AquaRing,
        MagnetRise,
        FlareBlitz,
        ForcePalm,
        AuraSphere,
        RockPolish,
        PoisonJab,
        DarkPulse,
        NightSlash,
        AquaTail,
        SeedBomb,
        AirSlash,
        X_Scissor,
        BugBuzz,
        DragonPulse,
        DragonRush,
        PowerGem,
        DrainPunch,
        VacuumWave,
        FocusBlast,
        EnergyBall,
        BraveBird,
        EarthPower,
        Switcheroo,
        GigaImpact,
        NastyPlot,
        BulletPunch,
        Avalanche,
        IceShard,
        ShadowClaw,
        ThunderFang,
        IceFang,
        FireFang,
        ShadowSneak,
        MudBomb,
        PsychoCut,
        ZenHeadbutt,
        MirrorShot,
        FlashCannon,
        RockClimb,
        Defog,
        TrickRoom,
        DracoMeteor,
        Discharge,
        LavaPlume,
        LeafStorm,
        PowerWhip,
        RockWrecker,
        CrossPoison,
        GunkShot,
        IronHead,
        MagnetBomb,
        StoneEdge,
        Captivate,
        StealthRock,
        GrassKnot,
        Chatter,
        Judgment,
        BugBite,
        ChargeBeam,
        WoodHammer,
        AquaJet,
        AttackOrder,
        DefendOrder,
        HealOrder,
        HeadSmash,
        DoubleHit,
        RoarofTime,
        SpacialRend,
        LunarDance,
        CrushGrip,
        MagmaStorm,
        DarkVoid,
        SeedFlare,
        OminousWind,
        ShadowForce,
        ClawSharpen,
        WideGuard,
        GuardShare,
        PowerShare,
        WonderRoom,
        PsychoShock,
        VenomShock,
        BodyPurge,
        RagePower,
        Telekinesis,
        MagicRoom,
        StrikeDown,
        JudoThrow,
        FireBurst,
        SludgeWave,
        RobeoftheButterfly,
        HeavyBomber,
        SynchroNoise,
        EleciBall,
        Soak,
        NitroCharge,
        Coil,
        AnkleSweep,
        AcidBomb,
        Trickery,
        SimpleBeam,
        AssembleCrew,
        YouFirst,
        Troll,
        EchoVoice,
        PaymentPlan,
        ClearSmog,
        AssistPower,
        FastGuard,
        SideChange,
        BoilingWater,
        ShellCrack,
        HealPulse,
        EvilEye,
        FreeFall,
        GearChange,
        OverheadThrow,
        CompleteBurn,
        Stall,
        Acrobat,
        MirrorType,
        Retaliation,
        Desperation,
        GiftPass,
        Purgatory,
        WaterOath,
        FireOath,
        GrassOath,
        VoltChange,
        BugResistance,
        GroundLeveling,
        FreezingBreath,
        DragonTail,
        CheerUp,
        EleciNet,
        WildVolt,
        DrillLiner,
        DoubleChop,
        HeartStamp,
        WoodHorn,
        SacredSword,
        ShellBlade,
        HeatStamp,
        GrassMixer,
        HeartRoller,
        CottonGuard,
        NightBurst,
        PsychoBreak,
        SweepSlap,
        WindStorm,
        AfroBreak,
        GearSaucer,
        FlamePlatform,
        TechnoBuster,
        AncientSong,
        SkinSword,
        FrozenWorld,
        Lightning,
        BlueFire,
        FireDance,
        FreezeBolt,
        ColdFlare,
        BackOut,
        IciclePolish,
        V_Generate,
        CrossFlame,
        CrossThunder
    };
}

namespace Type
{
    enum Effectiveness
    {
	Ineffective = 0,
	NotEffective = 1,
	Effective = 2,
	SuperEffective = 4
    };

    enum Type
    {
	Normal = 0,
	Fighting,
	Flying,
	Poison,
	Ground,
	Rock,
	Bug,
	Ghost,
	Steel,
	Fire,
	Water,
	Grass,
	Electric,
	Psychic,
	Ice,
	Dragon,
	Dark,
	Curse = 17
    };
}

namespace Ability
{
    enum Name
    {
        NoAbility,
        Stench,
        Drizzle,
        SpeedBoost,
        BattleArmor,
        Sturdy,
        Damp,
        Limber,
        SandVeil,
        Static,
        VoltAbsorb,
        WaterAbsorb,
        Oblivious,
        CloudNine,
        Compoundeyes,
        Insomnia,
        ColorChange,
        Immunity,
        FlashFire,
        ShieldDust,
        OwnTempo,
        SuctionCups,
        Intimidate,
        ShadowTag,
        RoughSkin,
        WonderGuard,
        Levitate,
        EffectSpore,
        Synchronize,
        ClearBody,
        NaturalCure,
        Lightningrod,
        SereneGrace,
        SwiftSwim,
        Chlorophyll,
        Illuminate,
        Trace,
        HugePower,
        PoisonPoint,
        InnerFocus,
        MagmaArmor,
        WaterVeil,
        MagnetPull,
        Soundproof,
        RainDish,
        SandStream,
        Pressure,
        ThickFat,
        EarlyBird,
        FlameBody,
        RunAway,
        KeenEye,
        HyperCutter,
        Pickup,
        Truant,
        Hustle,
        CuteCharm,
        Plus,
        Minus,
        Forecast,
        StickyHold,
        ShedSkin,
        Guts,
        MarvelScale,
        LiquidOoze,
        Overgrow,
        Blaze,
        Torrent,
        Swarm,
        RockHead,
        Drought,
        ArenaTrap,
        VitalSpirit,
        WhiteSmoke,
        PurePower,
        ShellArmor,
        AirLock,
        TangledFeet,
        MotorDrive,
        Rivalry,
        Steadfast,
        SnowCloak,
        Gluttony,
        AngerPoint,
        Unburden,
        Heatproof,
        Simple,
        DrySkin,
        Download,
        IronFist,
        PoisonHeal,
        Adaptability,
        SkillLink,
        Hydration,
        SolarPower,
        QuickFeet,
        Normalize,
        Sniper,
        MagicGuard,
        NoGuard,
        Stall,
        Technician,
        LeafGuard,
        Klutz,
        MoldBreaker,
        SuperLuck,
        Aftermath,
        Anticipation,
        Forewarn,
        Unaware,
        TintedLens,
        Filter,
        SlowStart,
        Scrappy,
        StormDrain,
        IceBody,
        SolidRock,
        SnowWarning,
        HoneyGather,
        Frisk,
        Reckless,
        Multitype,
        FlowerGift,
        BadDreams,
        BadAssembly,
        Encourage,
        Perversity,
        Anxiety,
        CompetitiveSpirit,
        Weak_kneed,
        CursedBody,
        HealingHeart,
        FriendCard,
        BrokenArmour,
        HeavyMetal,
        LightMetal,
        Multi_Scale,
        PoisonRampage,
        HeatRampage,
        Harvest,
        Telepathy,
        Inconsistent,
        Dustproof,
        PoisonSkin,
        Regeneration,
        PigeonHeart,
        SandThrow,
        MiracleSkin,
        Analyze,
        Illusion,
        Eccentric,
        SlipThrough,
        Mummy,
        EarthquakeSpiral,
        JusticeHeart,
        Wariness,
        MagicMirror,
        Herbivore,
        MischievousHeart,
        SandPower,
        IronBarbs,
        DarumaMode,
        VictoryStar,
        TurboBlaze,
        TeraVoltage
    };
}

namespace Item
{
    enum Name
    {
        NoItem,
        BigRoot,
        BlueScarf,
        BrightPowder,
        ChoiceBand,
        ChoiceScarf,
        ChoiceSpecs,
        DestinyKnot,
        ExpertBelt,
        FocusBand,
        FocusSash,
        FullIncense,
        GreenScarf,
        LaggingTail,
        LaxIncense,
        Leftovers,
        LuckIncense,
        MentalHerb,
        MetalPowder,
        MuscleBand,
        OddIncense,
        PinkScarf,
        PowerHerb,
        PureIncense,
        QuickPowder,
        ReaperCloth,
        RedScarf,
        RockIncense,
        RoseIncense,
        SeaIncense,
        ShedShell,
        SilkScarf,
        SilverPowder,
        SmoothRock,
        SoftSand,
        SootheBell,
        WaveIncense,
        WhiteHerb,
        WideLens,
        WiseGlasses,
        YellowScarf,
        ZoomLens,
        AmuletCoin,
        Antidote,
        Awakening,
        BerryJuice,
        BigPearl,
        BigMushroom,
        BlackBelt,
        BlackFlute,
        BlackSludge,
        BlackGlasses,
        BlueFlute,
        BlueShard,
        BurnHeal,
        Calcium,
        Carbos,
        Charcoal,
        CleanseTag,
        DampMulch,
        DeepSeaScale,
        DireHit,
        DragonScale,
        Elixir,
        EnergyRoot,
        EnergyPowder,
        EscapeRope,
        Ether,
        Everstone,
        ExpShare,
        FireStone,
        FlameOrb,
        FluffyTail,
        FreshWater,
        FullHeal,
        FullRestore,
        GooeyMulch,
        GreenShard,
        GrowthMulch,
        GuardSpec,
        HealPowder,
        HeartScale,
        Honey,
        HPUp,
        HyperPotion,
        IceHeal,
        Iron,
        KingsRock,
        LavaCookie,
        LeafStone,
        Lemonade,
        LifeOrb,
        LightBall,
        LightClay,
        LuckyEgg,
        Magnet,
        MaxElixir,
        MaxEther,
        MaxPotion,
        MaxRepel,
        MaxRevive,
        MetalCoat,
        Metronome,
        MiracleSeed,
        MooMooMilk,
        MoonStone,
        MysticWater,
        NeverMeltIce,
        Nugget,
        OldGateau,
        ParlyzHeal,
        Pearl,
        PokeDoll,
        Potion,
        PPMax,
        PPUp,
        Protein,
        RareCandy,
        RazorFang,
        RedFlute,
        RedShard,
        Repel,
        RevivalHerb,
        Revive,
        SacredAsh,
        ScopeLens,
        ShellBell,
        ShoalSalt,
        ShoalShell,
        SmokeBall,
        SodaPop,
        SoulDew,
        SpellTag,
        StableMulch,
        StarPiece,
        Stardust,
        SunStone,
        SuperPotion,
        SuperRepel,
        Thunderstone,
        TinyMushroom,
        ToxicOrb,
        TwistedSpoon,
        UpGrade,
        WaterStone,
        WhiteFlute,
        XAccuracy,
        XAttack,
        XDefend,
        XSpecial,
        XSpDef,
        XSpeed,
        YellowFlute,
        YellowShard,
        Zinc,
        IcyRock,
        LuckyPunch,
        DubiousDisc,
        SharpBeak,
        AdamantOrb,
        DampRock,
        HeatRock,
        LustrousOrb,
        MachoBrace,
        Stick,
        DragonFang,
        PoisonBarb,
        PowerAnklet,
        PowerBand,
        PowerBelt,
        PowerBracer,
        PowerLens,
        PowerWeight,
        DawnStone,
        DuskStone,
        Electirizer,
        Magmarizer,
        OddKeystone,
        OvalStone,
        Protector,
        QuickClaw,
        RazorClaw,
        ShinyStone,
        StickyBarb,
        DeepSeaTooth,
        DracoPlate,
        DreadPlate,
        EarthPlate,
        FistPlate,
        FlamePlate,
        GripClaw,
        IciclePlate,
        InsectPlate,
        IronPlate,
        MeadowPlate,
        MindPlate,
        SkyPlate,
        SplashPlate,
        SpookyPlate,
        StonePlate,
        ThickClub,
        ToxicPlate,
        ZapPlate,
        ArmorFossil,
        ClawFossil,
        DomeFossil,
        HardStone,
        HelixFossil,
        OldAmber,
        RareBone,
        RootFossil,
        SkullFossil,
        IronBall,
        GriseousOrb
    };
}

/* Old Stats

enum Stat
{
    Hp = 0,
    Attack,
    Defense,
    Speed,
    SpAttack,
    SpDefense,
    Evasion,
    Accuracy
};

*/

enum Stat
{
    Hp = 0,
    Attack = 1,
    Defense = 2,
    SpAttack = 3,
    SpDefense = 4,
    Speed = 5,
    Accuracy = 6,
    Evasion = 7,
    AllStats = 8
};

struct AbilityGroup {
    quint8 _ab[3];

    AbilityGroup() {
        _ab[0] = 0;
        _ab[1] = 0;
        _ab[2] = 0;
    }

    int ab(int num) const {
        return _ab[num];
    }
};

class PokeBaseStats
{
private:
    quint8 m_BaseStats[6];
public:
    PokeBaseStats(quint8 base_hp=80, quint8 base_att=80, quint8 base_def = 80, quint8 base_spAtt = 80, quint8 base_spDef = 80, quint8 base_spd = 80);

    quint8 baseHp() const;
    quint8 baseAttack() const;
    quint8 baseDefense() const;
    quint8 baseSpeed() const;
    quint8 baseSpAttack() const;
    quint8 baseSpDefense() const;

    void setBaseHp(quint8);
    void setBaseAttack(quint8);
    void setBaseDefense(quint8);
    void setBaseSpeed(quint8);
    void setBaseSpAttack(quint8);
    void setBaseSpDefense(quint8);

    quint8 baseStat(int stat) const;
    void setBaseStat(int stat, quint8 base);
};

/* Data that every pokemon of the same specy share. */
class PokeGeneral
{
    PROPERTY(Pokemon::uniqueId, num);
    PROPERTY(quint8, gen);
protected:
    PokeBaseStats m_stats;
    QSet<int> m_moves;
    AbilityGroup m_abilities;
    int m_types[2];
    int m_genderAvail;

    void loadMoves();
    void loadTypes();
    void loadAbilities();
    void loadGenderAvail();
public:
    PokeGeneral();

    const AbilityGroup &abilities() const;
    int genderAvail() const;

    const QSet<int>& moves() const;

    /* loads using num() */
    void load();
};

/* Data that is unique to a pokémon */
class PokePersonal
{
    PROPERTY(QString, nickname);
    PROPERTY(Pokemon::uniqueId, num);
    PROPERTY(quint16, item);
    PROPERTY(quint16, ability);
    PROPERTY(quint8, nature);
    PROPERTY(quint8, gender);
    PROPERTY(bool, shiny);
    PROPERTY(quint8, happiness);
    PROPERTY(quint8, level);
    PROPERTY(quint8, gen);
protected:
    int m_moves[4];

    quint8 m_DVs[6];
    quint8 m_EVs[6];

    /* checks if the sum of the EVs isn't too high and reduces EVs in all stats but *stat* in order to keep that true */
    void controlEVs(int stat);
public:
    PokePersonal();

    /* -1 if the nature is hindering, 0 if neutral and 1 if it boosts that stat */
    int natureBoost(int stat) const;
    int move(int moveSlot) const;
    /* resets everything to default values */
    void reset();
    /* Removes / Reset things if they are wrong */
    void runCheck();

    void setMove(int moveNum, int moveSlot, bool check=false) throw (QString);
    int addMove(int moveNum, bool check = false) throw (QString);

    bool hasMove(int moveNum);

    quint8 DV(int stat) const;
    void setDV(int stat, quint8 DV);

    quint8 EV(int stat) const;
    int EVSum() const;

    void setEV(int stat, quint8 EV);
};

/* Contains / loads the graphics of a pokemon */
class PokeGraphics
{
public:
    PokeGraphics();
    QPixmap picture(); /* just gives the already loaded picture */
    QPixmap picture(int gender, bool shiny); /* loads a new picture if necessary, anyway gives the right picture */
    QIcon icon();
    QIcon icon(const Pokemon::uniqueId &pokeid);


    void setNum(Pokemon::uniqueId num);
    void setGen(int gen);
    Pokemon::uniqueId num() const;
    int gen() const;

    void load(int gender, bool shiny);
    void loadIcon(const Pokemon::uniqueId &pokeid);
protected:
    /* This is the current implementation, but an implemenation where more than one
       image is stored can do to */
    QPixmap m_picture;
    QIcon m_icon;
    Pokemon::uniqueId m_num;
    int m_storedgender;
    int m_gen;

    bool m_storedshininess;
    bool m_uptodate;

    void setUpToDate(bool uptodate);
    bool upToDate() const;
};

class PokeTeam : virtual public PokeGeneral, virtual public PokePersonal, virtual public PokeGraphics
{
public:
    PokeTeam();

    Pokemon::uniqueId num() const;
    void setNum(Pokemon::uniqueId num);
    void setGen(int gen);
    int gen() const;
    void runCheck();

    int stat(int statno) const;

    /* load various data from the pokenum */
    void load();
    /* display automatically the right picture */
    QPixmap picture();
    QIcon icon();

    void loadFromXml(const QDomElement &el);
    QDomElement & toXml(QDomElement &dest) const;
};

class Team
{
protected:
    PokeTeam m_pokes[6];
    quint8 m_gen;

public:
    Team();
    quint8 gen() const {return m_gen;}
    void setGen(int gen);

    const PokeTeam & poke(int index) const {return m_pokes[index];}
    PokeTeam & poke(int index) {return m_pokes[index];}
};

class TrainerTeam
{
    PROPERTY(quint16, avatar);
    PROPERTY(QString, defaultTier);
protected:
    Team m_team;
    QString m_trainerNick;
    QString m_trainerInfo;
    QString m_trainerWin;
    QString m_trainerLose;

public:
    TrainerTeam();

    const Team & team() const;
    Team & team();

    void setTrainerInfo(const QString &newinfo);
    void setTrainerWin(const QString &newwin);
    void setTrainerLose(const QString &newlose);
    void setTrainerNick(const QString &newnick);

    const QString & trainerInfo() const;
    const QString & trainerWin() const;
    const QString & trainerLose() const;
    const QString & trainerNick() const;

    bool loadFromFile(const QString &path);
    bool saveToFile(const QString &path) const;
    bool importFromTxt(const QString &path);
    QString exportToTxt() const;
};


/* Dialog for loading/saving team */
/* The third argument, if non null, gives the path the user chose */
bool saveTTeamDialog(const TrainerTeam &team, const QString &defaultPath = QObject::tr("Team/trainer.tp"), QString *chosenPath=0);
bool loadTTeamDialog(TrainerTeam &team, const QString &defaultPath = QObject::tr("Team/"), QString *chosenPath=0);


QDataStream & operator << (QDataStream & out,const Team & team);
QDataStream & operator << (QDataStream & out,const TrainerTeam & trainerTeam);

QDataStream & operator >> (QDataStream & in,Team & team);
QDataStream & operator >> (QDataStream & in,PokeTeam & Pokemon);
QDataStream & operator >> (QDataStream & in,TrainerTeam & trainerTeam);


QDataStream & operator << (QDataStream & out,const PokePersonal & Pokemon);
QDataStream & operator >> (QDataStream & in,PokePersonal & Pokemon);

inline uint qHash(const Pokemon::uniqueId &key)
{
    return qHash(key.toPokeRef());
}

QDataStream & operator << (QDataStream &out, const Pokemon::uniqueId &id);
QDataStream & operator >> (QDataStream &in, Pokemon::uniqueId &id);

#endif // POKEMONSTRUCTS_H
