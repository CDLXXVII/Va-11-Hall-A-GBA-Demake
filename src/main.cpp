#include "bn_core.h"

#include "bn_string.h"
#include "bn_audio.h"
#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_bg_palettes.h"
#include <bn_sprite_palette_ptr.h>
#include <bn_string_view.h>
#include "bn_affine_bg_ptr.h"
#include "bn_affine_bg_builder.h"
#include "bn_affine_bg_actions.h"
#include "bn_affine_bg_attributes.h"
#include "bn_affine_bg_mat_attributes.h"
#include "bn_affine_bg_animate_actions.h"
#include "bn_affine_bg_attributes_hbe_ptr.h"
#include "bn_affine_bg_pivot_position_hbe_ptr.h"
#include "bn_affine_bg_mat_attributes_hbe_ptr.h"
#include "bn_regular_bg_actions.h"
#include "bn_regular_bg_builder.h"
#include "bn_regular_bg_attributes.h"
#include "bn_sprite_text_generator.h"
#include "bn_regular_bg_animate_actions.h"
#include "bn_regular_bg_position_hbe_ptr.h"
#include "bn_regular_bg_attributes_hbe_ptr.h"
#include "bn_blending.h"
#include "bn_bgs_mosaic.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_builder.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_first_attributes.h"
#include "bn_sprite_third_attributes.h"
#include "bn_sprite_position_hbe_ptr.h"
#include "bn_sprite_first_attributes_hbe_ptr.h"
#include "bn_sprite_third_attributes_hbe_ptr.h"
#include "bn_sprite_affine_second_attributes.h"
#include "bn_sprite_regular_second_attributes.h"
#include "bn_sprite_affine_second_attributes_hbe_ptr.h"
#include "bn_sprite_regular_second_attributes_hbe_ptr.h"
#include <bn_random.h>
#include <bn_bg_palette_actions.h>
#include <bn_bg_palette_ptr.h>
#include "bn_sound_items.h"
#include "bn_music_items.h"
#include <bn_sprite_palette_ptr.h>
#include <bn_array.h>

#include "bn_affine_bg_items_anna.h"
#include "bn_sprite_items_anna_eyes.h"
#include "bn_sprite_items_anna_mouth.h"

#include "bn_regular_bg_items_gil.h"
#include "bn_sprite_items_gil_eyes.h"
#include "bn_sprite_items_gil_mouth.h"
#include "bn_regular_bg_items_dana.h"
#include "bn_sprite_items_kim_spr.h"
#include "bn_sprite_items_dana_eyes.h"
#include "bn_sprite_items_dana_mouth.h"
#include "bn_regular_bg_items_donovan.h"
#include "bn_sprite_items_donovan_eyes.h"
#include "bn_sprite_items_donovan_mouth.h"
#include "bn_regular_bg_items_ingram.h"
#include "bn_sprite_items_ingram_eyes.h"
#include "bn_sprite_items_ingram_mouth.h"

#include "bn_regular_bg_items_sei.h"
#include "bn_sprite_items_sei_eyes.h"
#include "bn_sprite_items_sei_mouth.h"
#include "bn_sprite_items_sei_helmet.h"
#include "bn_regular_bg_items_kim.h"
#include "bn_sprite_items_kim_eyes.h"
#include "bn_sprite_items_kim_mouth.h"

#include "bn_regular_bg_items_bg.h"
#include "bn_regular_bg_items_textbox.h"
#include "bn_regular_bg_items_malevich.h"
#include "bn_sprite_items_fan.h"

#include "bn_regular_bg_items_bluebg.h"
#include "bn_regular_bg_items_break_placeholder.h"

#include "bn_regular_bg_items_frame.h"
#include "bn_sprite_items_amount.h"
#include "bn_sprite_items_slot.h"
#include "bn_sprite_items_delta.h"
#include "bn_sprite_items_karmotrine.h"
#include "bn_sprite_items_bronson.h"
#include "bn_sprite_items_adelhyde.h"
#include "bn_sprite_items_flanergide.h"
#include "bn_sprite_items_ice.h"
#include "bn_sprite_items_age.h"
#include "bn_sprite_items_shaker.h"
#include "bn_sprite_items_shaker_pulse.h"
#include "bn_sprite_items_shaker_bar.h"
#include "bn_sprite_items_cursor.h"
//#include "bn_sprite_palette_items_pulse_palette_1.h"
//#include "bn_sprite_palette_items_pulse_palette_2.h"
//#include "bn_sprite_palette_items_pulse_palette_3.h"
//#include "bn_sprite_palette_items_pulse_palette_4.h"
//#include "bn_sprite_palette_items_pulse_palette_5.h"
#include "bn_sprite_items_sugar_rush.h"
#include "bn_sprite_items_bad_touch.h"
#include "bn_sprite_items_beer.h"
#include "bn_sprite_items_bleeding_jane.h"
#include "bn_sprite_items_bloom_light.h"
#include "bn_sprite_items_blue_fairy.h"
#include "bn_sprite_items_branditini.h"
#include "bn_sprite_items_cobalt_velvet.h"
#include "bn_sprite_items_crevice_spike.h"
#include "bn_sprite_items_flaming_moai.h"
#include "bn_sprite_items_fedora.h"
#include "bn_sprite_items_fluffy_dream.h"
#include "bn_sprite_items_fringe_weaver.h"
#include "bn_sprite_items_glitchbottle.h"
#include "bn_sprite_items_grizzly_temple.h"
#include "bn_sprite_items_gut_punch.h"
#include "bn_sprite_items_marsblast.h"
#include "bn_sprite_items_mercury_blast.h"
#include "bn_sprite_items_moonblast.h"
#include "bn_sprite_items_piano_man.h"
#include "bn_sprite_items_piano_woman.h"
#include "bn_sprite_items_piledriver.h"
#include "bn_sprite_items_rum.h"
#include "bn_sprite_items_sparkle_star.h"
#include "bn_sprite_items_sunshine_cloud.h"
#include "bn_sprite_items_suplex.h"
#include "bn_sprite_items_tea.h"
#include "bn_sprite_items_zen_star.h"
#include "bn_sprite_items_absynthe.h"
#include "bn_sprite_items_success.h"
#include "bn_sprite_items_fail.h"


#include "bn_sprite_items_anna_tv.h"


#include "common_info.h"
#include "common_variable_8x8_sprite_font.h"



int line = 0;
int order = 0;
int pos = 0;
int karmotrine_memory = 0;
int karmotrine_prev = 0;
bool play_flag = false;
bool drunk = false;
int activity = 1; // 0 - title screen, 1 - barground, 2 - mixing, 3 - break screen
int day = 0; // current day (half-day really)

int ingr[3] = 
{
0, // 1 - sweet, 2 - gut punch, 0 - other
0, // 1 - sweet, 2 - piledriver, 3 - suplex, 0 - other
0 // 1 - sweet, 2 - fringe weaver, 0 - other
};

int sei = 0; // 0 - sober, 1 - early, 2 - drunk

int kim[2] = 
{
0, // 0 - sober, 1 - drunk
0, // 0 - fail, 1 - bubbly, 2 - sweet, 3 - bitter, 4 - sour, 5 - spicy, 6 - bitter2, 7 - sour2
};

namespace game_text // Contains all dialogue phrases and situations
{
    constexpr const char* lines[] = // an array for the text lines
    {
        "Anna: Pssst. ",
        " ",
        " ",
        "Anna: Hey, over here. ",
        " ",
        " ",
        "Anna: BOO! ",
        " ",
        " ",
        "Anna: How's that for an entrance? ",
        " ",
        " ",
        "Anna: ... ",
        " ",
        " ",
        "Anna: Come on Jo, look sharp! The game's",
        "starting and the player needs a good first",
        "impression of its main character.",
        "Anna: I know you served a bunch of",
        "tuxedo-clad Corgis over the weekend",
        "and the bar will eventually close.",
        "Anna: ...and I'll admit my little prank on",
        "you might've gone a little overboard.",
        " ",
        "Anna: But remember, life is 90% how you",
        "take it! Stay focused and look at the",
        "brighter side of things.",
        "Anna: I have no idea what the brighter",
        "side is, but you should totally",
        "find it.",
        "Anna: In any case, you should totally",
        "check that parcel you just got.",
        "",
        "Anna: See ya!",
        "",
        "",
        "Jill: ..!",
        "",
        "",
        "Jill: Oh... *yawn* just a dream.",
        "",
        "",
        "Jill: (Hm? There's something near the",
        "door)",
        "",
        "Jill: G'evening.",
        "",
        "",
        "???: Ah! Hey there, Jill.",
        "",
        "",
        "Jill: ...",
        "",
        "",
        "Jill: Oh. Hey, John.",
        "",
        "",
        "???: ...",
        "",
        "",
        "Jill: When will you admit you have a",
        "John face, Gil?",
        "",
        "Gillian: When you let people call you Jules.",
        "",
        "",
        "Jill: Quiet.",
        "",
        "",
        "Gillian: Are you okay? You look distracted.",
        "",
        "",
        "Jill: Where's Boss?",
        "",
        "",
        "Gillian: Dunno. She went out to buy some",
        "stuff and...",
        "",
        "Gillian: Did you hear what i just told you?",
        "",
        "",
        "Jill: You said something?",
        "",
        "",
        "Gillian: Yes. That you look distracted.",
        "Very, very distracted.",
        "",
        "Jill: It's nothing. I'm just thinking",
        "about... Stuff.",
        "",
        "Gillian: What stuff?",
        "",
        "",
        "Jill: Well, I have to pay rent by the 30th,",
        "which is always stressful, and -",
        "",
        "Gillian: Ah.",
        "",
        "",
        "Jill: (There's also the fact that i spent",
        "a full hour yesterday apparently talking",
        "to myself.)",
        "Jill: (Not to mention the fact that",
        "two days ago, I found out the bar is at",
        "risk of closing.)",
        "Jill: (So not only is my life being",
        "shaken up, I'm apparently going",
        "crazy.)",
        "Jill: (On top of that, neutering Fore",
        "left me with a completely empty wallet)",
        "",
        "Jill: (And I'll get evicted if I miss",
        "rent again...)",
        "",
        "Jill: (And there're all the beer cans",
        "around my apartment, and...)",
        "",
        "Gillian: Jill!",
        "",
        "",
        "Jill: Sorry, did you say something?",
        "",
        "",
        "Gillian: ...can you really work today?",
        "",
        "",
        "Jill: Of course I can!",
        "",
        "",
        "Gillian: Let's go through the basics then,",
        "shall we? Just in case.",
        "",
        "Jill: ...",
        "",
        "",
        "Gillian: If you can make a Piano Man, I'll",
        "skip the rest. But. Bear with me for",
        "a second here, okay?",
        "Jill: ...",
        "",
        "",
        "Gillian: Let's start with a Sugar Rush.",
        "",
        "",
        "Gillian: To open a recipe book, push",
        "the L button.",
        "",
        "Gillian: Look for the recipe using the",
        "navigtion bar in the recipe book that",
        "will show up on the top left.",
        "Gillian: You can also sort drinks by",
        "flawors like 'Sweet' or types",
        "like 'Manly'.",
        "Gillian: Select the desired amount of",
        "ingredients in their cells with an",
        "A button.",
        "Jill: Gil...",
        "",
        "",
        "Gillian: When done, push the B",
        "button, and then push it again",
        "to stop mixing.",
        "Gillian: Push the B button again",
        "to serve and that'll be all.",
        "",
        "Gillian: Oh, but if the drink looks messed",
        "up, you'll need to push the R button",
        "and try again.",
        "Gillian: You can push the R button at any",
        "time. Even when the shaker is moving. Don't",
        "be afraid to use it.",
        "Gillian: The interface also keeps track of",
        "the orders. To read it, push the SELECT",
        "button.",
        "Jill: Gil, I'm the one that went through",
        "the formal BTC instruction.",
        "",
        "Gillian: Then this should be no problem!",
        "",
        "",
        "Jill: *sigh*",
        "",
        "",
        "",
        "",
        "",
        "Gil wants either a Sugar Rush or a Piano",
        "Man. If I mess up the ingredients or the",
        "drink i can press the R button.",
        "Jill: Here.",
        "",
        "",
        "Gillian: This is... not a Sugar Rush",
        "",
        "",
        "Gillian: Um... let's try something else.",
        "",
        "",
        "Jill: Here. Happy now?",
        "",
        "",
        "Gillian: A little, but not quite.",
        "Let's do one more.",
        "",
        "Jill: *sigh*",
        "",
        "",
        "Gillian: I know, I know. Please",
        "humor me for a bit.",
        "",
        "Gillian: Some drinks need to blended.",
        "",
        "",
        "Gillian: This is done by shaking it for",
        "over 5 seconds. You can tell it's being",
        "blended when the shaker moves faster.",
        "Gillian: You also need to check if the",
        "drink should be served on the rocks",
        "or aged.",
        "Gillian: Check Ice and Age buttons on",
        "the side to select the one you need.",
        "",
        "Gillian: And in case it wasn't obvious.",
        "'On the rocks' means you have to toggle ",
        "the 'Ice' tab.",
        "Gillian: It should be noted that the",
        "station will add the ice after mixing.",
        "",
        "Gillian: It's not something you should",
        "mind though. Just a fun fact.",
        "",
        "Jill: ...",
        "",
        "",
        "Gillian: Give me a Moonblast and I'll",
        "leave you alone.",
        "",
        "Gillian: Keep in mind what i said!",
        "",
        "",
        "Jill: Yeah, yeah...",
        "",
        "",
        "",
        "",
        "",
        "Let's give Gil a Moonblast. Blended",
        "drinks need to be left to mix for at",
        "least 5 seconds before i stop the shaker.",
        "Jill: Here.",
        "",
        "",
        "Gillian: Um...",
        "",
        "",
        "Gillian: Uh...",
        "",
        "",
        "Gillian: You didn't blow everything",
        "when mixing. Let's leave it at that.",
        "We need to start working.",
        "Jill: Finally",
        "",
        "",
        "Jill: Here, did i amuse you for long enough?",
        "",
        "",
        "Gillian: You did. Sorry to hold you.",
        "",
        "",
        "Gillian: Let's get working.",
        "",
        "",
        "Jill: Yeah.",
        "",
        "",
        "Jill: Here. Happy now?",
        "",
        "",
        "Gillian: Yes. Very. I stand corrected.",
        "",
        "",
        "Gillian: Now, let's get working.",
        "",
        "",

        "Gillian: Oh, yeah! Before I forget!",
        "",
        "",
        "Jill: Hm?",
        "",
        "",
        "Gillian: You can make any drink big by",
        "doubling the amount of ingredients.",
        "",
        "Gillian: But if the recipe already has",
        "over 10 ingredients, the drink is",
        "already big.",
        "Gillian: Oh, and if a recipe says",
        "'Optional Karmotrine' it means you can",
        "use none or fill it to the brim.",
        "Gillian: Optional Karmotrine doesn't",
        "count towards making a big drink,",
        "of course.",
        "Gillian: Karmotrine is the alcoholic",
        "factor in a drink. It doesn't change the",
        "taste but the amount still has an effect.",
        "Gillian: If you add too much of it, the",
        "client will get drunk faster. So please",
        "be mindful of that.",
        "Jill: Are you done with the exposition?",
        "",
        "",
        "Gillian: Now I am. Yeah.",
        "",
        "",

        "Dana: Hey, guys!",
        "",
        "",
        "Jill: Oh Bo-... eh?",
        "",
        "",
        "Jill: W-Who's that?",
        "",
        "",
        "Dana: I don't know. Found her while I",
        "was out shopping.",
        "",
        "Gillian: Why bring her here?",
        "",
        "",
        "Dana: Well, it was either leave her",
        "outside at the mercy of the society's",
        "finest or bring her unconcious here.",
        "Jill: She's going to make such a ruckus",
        "when she wakes up. You know that.",
        "",
        "Dana: That's up for you to deal with.",
        "I'll be in my office.",
        "",
        "Jill: You can't just push that",
        "responsibility on to us! We have work",
        "to do, damn it!",
        "Dana: There're two of you! Believe in",
        "yourselves!",
        "",
        "Jill: *sigh*",
        "",
        "",
        "Gillian: Do you think Chief knocked",
        "her out?",
        "",
        "Jill: Nah, that's unlikely. She'd be",
        "crowing about it or taunting us if that",
        "were the case.",
        "Jill: And it's not like her to pick on",
        "such a small girl... at least not",
        "unprovoked.",
        "Gillian: We'll just need to keep it",
        "quiet. She seems to be just sleeping",
        "soundly, not comatose.",
        "Jill: Yeah.",
        "",
        "",
        "Gillian: Okay then Time to start",
        "the night!",
        "",
        "Jill: Yes, I'll start working while",
        "YOU go clean the bathroom.",
        "",
        "Gillian: Um... come again?",
        "",
        "",
        "Jill: While you spend the whole week and",
        "Monday doing god-knows-what, we've had",
        "some interesting clients come in.",
        "Jill: Dogs. Lots of 'em.",
        "",
        "",
        "Gillian: You're joking.",
        "",
        "",
        "Jill: Gil, you've known me for how long",
        "now? Do I look like the kind of woman who",
        "would make a joke like that?",
        "Gillian: Well...",
        "",
        "",
        "Jill: So! As a punishment for leaving me",
        "to deal with all of that on my lonesome,",
        "you'll be in charge of the bathrooms.",
        "Jill: Have fun!",
        "",
        "",
        "Gillian: Just that? Fine. I see no",
        "problem.",
        "",
        "Gillian: Where's the cleaning stuff?",
        "",
        "",
        "Jill: Here.",
        "",
        "",
        "Gillian: ...you brought that from home,",
        "didn't you?",
        "",
        "Jill: That I did.",
        "",
        "",
        "Gillian: Fiiiiiiiiiiine.",
        "",
        "",
        "Jill: (With that out of the way, let's",
        "play some music on the new 'Jukebox'.)",
        "",
        "Jill: (This model needs to have all of",
        "its 12 slots filled with songs before",
        "it can start.)",
        "Jill: (I wonder what was the logic behind",
        "that decision...)",
        "",
        "Jill: (Now what songs do we have?)",
        "",
        "",
        "Jill: (Wait, we don't have 12 songs.",
        "Oh well.)",
        "",
        "Jill: Time to mix drinks and change lives.",
        "",
        "",
        "???: Hey You! Get me a Beer.",
        "",
        "",
        "Jill: Oh! Sure. Right on it.",
        "",
        "",
        "",
        "",
        "",
        "He wants a Beer. He looks like the big",
        "guy, though.",
        "",
        "Jill: Here.",
        "",
        "",
        "???: ...",
        "",
        "",
        "???: Listen, kid. I'm a man. An adult. If",
        "I wanted something that wouldn't get me",
        "drunk, do you think I'd come to a bar?",
        "???: Let's try this again. Give me a Beer.",
        "Bravo Echo Echo Romeo: BEER.",
        "",
        "???: If you're incapable of doing that, at",
        "least give me something alcoholic.",
        "",
        "Jill: R-Right...",
        "",
        "",
        "",
        "",
        "",
        "Dammit, Jill. Get it together. He wants a",
        "Beer! B. E. E. R!",
        "",
        "Jill: Here.",
        "",
        "",
        "???: Still not a trace of alcohol in this",
        " shit.",
        "",
        "???: Whatever. Leave it. You're worse than",
        "my second wife.",
        "",
        "???: Don't expect me to pay you for this ",
        "one, you hear?",
        "",
        "Jill: Sure.",
        "",
        "",

        "Jill: How about this?",
        "",
        "",
        "???: I guess this'll do. You're a slow",
        "one, you know that?",
        "",
        "Jill: (I'm slow then...)",
        "",
        "",

        "Jill: Here.",
        "",
        "",
        "???: See? You can do it if you",
        "put your mind to it.",
        "",
        "Jill: Thanks... I guess?",
        "",
        "",

        "Jill: Here you go.",
        "",
        "",
        "???: *sigh*",
        "",
        "",
        "???: Listen, kid. I don't know where",
        "you're from but in this country, that",
        "isn't what you call a Beer.",
        "???: Seems like it'll get me drunk, at",
        "least. But don't expect me to pay",
        "for it.",
        "Jill: Don't worry.",
        "",
        "",
        "",
        "",
        "",

        "Jill: Here you go.",
        "",
        "",
        "???: No, no. This isn't gonna cut it.",
        "Gimme a big one.",
        "",
        "Jill: Um... sure.",
        "",
        "",
        "",
        "",
        "",
        "That Beer wasn't enough, apparently.",
        "",
        "",
        "Jill: Here.",
        "",
        "",
        "???: Let's see...",
        "",
        "",
        "???: Psheh! You think this is funny?",
        "Giving me something that won't get me",
        "wasted?",
        "???: Yeah, whatever. Leave it at that.",
        "",
        "",
        "Jill: Funny... sure.",
        "",
        "",

        "Jill: Here.",
        "",
        "",
        "???: Hmph...",
        "",
        "",
        "???: This better get me wasted. For",
        "your sake.",
        "",
        "Jill: Sure, no worries there.",
        "",
        "",

        "Jill: And now?",
        "",
        "",
        "???: I said a BIG one, brat. BIG! Like",
        "my dick!",
        "",
        "???: Forget it. These two will have to do.",
        "",
        "",

        "Jill: How about this one?",
        "",
        "",
        "???: Ah, yes. Now, this one's fit for a man",
        "like me.",
        "",
        "Jill: Right...",
        "",
        "",

        "Jill: Here you go.",
        "",
        "",
        "???: Yeah, this one's good. Pretty good,",
        "in fact. Nice job.",
        "",
        "Jill: ...",
        "",
        "",

        "???: You're lucky I was in a meeting close",
        "by. This hell hole could certainly use a",
        "presence like mine.",
        "???: Although to be fair, work has taken",
        "me to worse hell holes. Like",
        "New Jersey III.",
        "Jill: Huh...",
        "",
        "",
        "Jill: What kind of work do you do,",
        "mister...?",
        "",
        "Donovan: You're talking to Donovan D.",
        "Dawson, chief editor and owner of",
        "The Augmented Eye.",
        "Donovan: Nothing gets published there",
        "without my blessings.",
        "",
        "Jill: (The day started with quite the",
        "interesting fellow, it seems.)",
        "",
        "Jill: So you're the one to blame for the",
        "barrage of daily articles on",
        "Alice_Rabbit, then?",
        "Donovan: Hey! People love those articles -",
        "they love reading about that urban legend.",
        "",
        "Donovan: Can you blame 'em? The idea of",
        "some wildcard hacker working for their",
        "own goals and nobody else's...",
        "Donovan: That's the kind of corny shit",
        "that brings the clicks. From all kinds",
        "people.",
        "Donovan: And clicks bring money, and",
        "money brings nice stuff.",
        "",
        "Donovan: Stuff like cars, and houses,",
        "and plastic surgery for the missus and",
        "her kids.",
        "Jill: Well, I'm not complaining about the",
        "fact that you write about the hacker. Just",
        "that you write about them every single day.",
        "Jill: Some of it isn't even news. Just",
        "speculations or... copycats.",
        "",
        "Jill: I can't read your newspaper's daily",
        "feed without running into at least ONE",
        "article about Alice_Rabbit.",
        "Donovan: Well, first of all: I don't write",
        "about it, my interns do.",
        "",
        "Donovan: The poor bastards think it'll",
        "help make them full-time employees.",
        "",
        "Donovan: I'm just capitalizing on this",
        "topic while it's popular.",
        "",
        "Donovan: And second: You're tired of one",
        "article about a supposed hacker...",
        "",
        "Donovan: But not all the daily stories",
        "about murders and other horrors?",
        "",
        "Jill: Well, I always filter out that",
        "section. I don't want to start my day",
        "scared and bitter.",
        "Jill: I have enough pressure and problems",
        "as is. I don't need to add Glitch City's",
        "lovely citizens to the list.",
        "Donovan: You're smarter than you look, kid.",
        "But if more people were like you, I'd go",
        "bankrupt from the lack of traffic.",
        "Donovan: ...still. Maybe my job would be",
        "easier.",
        "",
        "Jill: How so?",
        "",
        "",
        "Donovan: People get desenti... deseszi...",
        "people get bored of a certain kind of news",
        "after seeing it repeatedly.",
        "Donovan: When I started in this job, it",
        "only took the news of some elderly woman",
        "being killed to guarantee clicks.",
        "Donovan: Now, you need an elderly woman",
        "carrying a sick baby boy getting hit by a",
        "truck.",
        "Donovan: Death's not enough. They need a",
        "full sob story behind it.",
        "",
        "Donovan: That's why I like those urban",
        "legends: they're easier to write about",
        "and you can make up any shit you want.",
        "Donovan: Spam them while they're hot.",
        "And even people like you, people who avoid",
        "the murder stories, will see them.",
        "Donovan: That brings money. And like I",
        "said, money's good.",
        "",
        "Jill: (Huh, I guess he has a point...)",
        "",
        "",
        "Jill: What about the opinion columns?",
        "Aren't those a good source of traffic",
        "too?",
        "Donovan: Oh, I hate those brats. They",
        "just write about how they're better",
        "than everyone else.",
        "Donovan: They might also write about",
        "how everyone that likes a certain",
        "something should be sodomized.",
        "Donovan: The worst part about that is",
        "they KNOW half of our clicks come from",
        "them so they get all diva-like on my ass.",
        "Jill: I think you're being too harsh.",
        "What about...?",
        "",
        "Jill: ...no,wait. I was thinking of",
        "another newspaper. Yeah, the columnists on",
        "your page are annoying.",
        "Donovan: See?",
        "",
        "",
        "Donovan: The kid on that restaurant critique",
        "column... um... uh... shit, forgor that",
        "brat's name.",
        "Jill: Restaurant? I believe that's...",
        "",
        "",
        "Donovan: That kid. Couldn't care less about",
        "his name.",
        "",
        "Donovan: Anyway. His column is the least",
        "visited of the bunch. He gets less hits",
        "than the obituaries.",
        "Donovan: However, he still insists that i",
        "keep paying for his adventures to",
        "outargeous restaurants.",
        "Donovan: I wouldn't have any problem with",
        "that if he actually wrote about half of",
        "the places he visits.",
        "Jill: How so?",
        "",
        "",
        "Donovan: He rarely writes about the places",
        "the newspaper sends him to!",
        "",
        "Donovan: I've even heard he tries to get",
        "free meals by proclaiming that he's a",
        "food critic.",
        "Donovan: Poor bastard only gets laughed at",
        "when he says that.",
        "",
        "Jill: I do remember some guy coming here",
        "asking for free drinks, and saying he",
        "was a critic or whatever.",
        "Donovan: Did he look like a fat child with",
        "a really small face?",
        "",
        "Jill: No.",
        "",
        "",
        "Donovan: Wasn't this one then.",
        "",
        "",
        "Donovan: Anyway, all this talk made me",
        "thirsty. Try to give me a Beer thi time,",
        "please.",
        "Jill: Coming right up.",
        "",
        "",
        "",
        "",
        "",
        "Beer again. This man likes his Beers.",
        "They come cheaper in bulk at the store,",
        "though",
        "Jill: Here you go.",
        "",
        "",
        "Donovan: *sigh*",
        "",
        "",
        "Donovan: Look, brat. You're not helping",
        "this hell hole by messing up my orders.",
        "",
        "Donovan: This won't even make you look",
        "sexy.",
        "",
        "Jill: (Yeah, great loss for me.)",
        "",
        "",

        "Jill: Done.",
        "",
        "",
        "Donovan: Hey! I want one of those bubbly",
        "drinks that are served in big mugs.",
        "",
        "Donovan: Prefferably by big tittied",
        "blondes in dresses showing lots of",
        "clevage.",
        "Donovan: Tell me what you call those",
        "drinks so I can order them.",
        "",
        "Jill: ...",
        "",
        "",

        "Jill: One beer.",
        "",
        "",
        "Donovan: Yeah, this is a Beer alright.",
        "",
        "",
        "Donovan: Keep it up, kid. You'll get",
        "better some day.",
        "",
        "Jill: ...",
        "",
        "",

        "Jill: Here.",
        "",
        "",
        "Donovan: Ahhhh, it's the big things that",
        "make life worthwhile...",
        "",
        "Jill: What about big troubles?",
        "",
        "",
        "Donovan: Did i stutter, kid?",
        "",
        "",
        "Donovan: Right...",
        "",
        "",

        "Donovan: So, tell me. Do you see many",
        "celebrities in this hell hole?",
        "",
        "Jill: Please stop reffering to this place",
        "as a hell hole.",
        "",
        "Donovan: If a place smells like soap and",
        "dog piss, I'm within my constitutional",
        "rights to call it a hell hole.",
        "Gillian: I'M DOING MY BEST HERE, THANK",
        "YOU VERY MUCH!",
        "",
        "Donovan: Who was that?",
        "",
        "",
        "Jill: Nobody important.",
        "",
        "",
        "Gillian: HEY! I HEARD THAT!",
        "",
        "",
        "Donovan: Don't be offended by what I say,",
        "kid. I'm insulting the building, not you.",
        "",
        "Donovan: You can think of it as a small",
        "hole in hell rather than a hellish hole,",
        "if you like.",
        "Jill: Charming.",
        "",
        "",
        "Donovan: So, Celebrities...",
        "",
        "",
        "Jill: Not really. At least, not that I",
        "know of. Why?",
        "",
        "Donovan: Well... To begin with, you have",
        "a serious VIP as a client but I don't",
        "see you losing your shit.",
        "Donovan: You're not making me feel",
        "special, honey.",
        "",
        "Donovan: And second, because I'm always",
        "up for gossip regarding famous people.",
        "",
        "Donovan: Especially the red carpet kind",
        "of famous.",
        "",
        "Donovan: Those folks people pretend to",
        "love but actually want to see fall",
        "from grace.",
        "Jill: 'Pretend to love'? 'Fall from",
        "grace'?",
        "",
        "Donovan: Why do you think that gossip",
        "about famous people alway sells?",
        "",
        "Donovan: People pretend that they love",
        "celebs, but what they really want is to",
        "see their idols torn down to their level.",
        "Donovan: They want to see them suffer. To",
        "get their comeuppance for daring to be so",
        "much more successful than them!",
        "Jill: Nah, I think gossip is just something",
        "everyone enjoys but nobody wants to admit",
        "to enjoying.",
        "Donovan: You thought wrong. But even if",
        "you were right, it wouldn't change the",
        "fact that people love that kind of stuff.",
        "Donovan: They want to escape their lives",
        "by living somebody else's.",
        "",
        "Jill: Sadly, I fail to see the appeal in",
        "that whole thing.",
        "",
        "Jill: What do I care if this guy I saw in",
        "some random movie was wearing socks with",
        "sandals or if they're dating god-knows-who?",
        "Jill: (Granted, socks with sandals is",
        "practically a public indecency, but",
        "still.)",
        "Donovan: Oh, please. As a bartender, I bet",
        "you have a strong voyeuristic streak. Your",
        "kind always loves to hear that stuff.",
        "Donovan: Just like hairdressers! This",
        "sounds hypocritical coming from you.",
        "",
        "Jill: E-even if that's the case, I don't",
        "sensationalize what people do.",
        "",
        "Jill: I don't make it more than 'That",
        "person you know from TV acts like a",
        "human'.",
        "Jill: 'Sensationalize' is the key word",
        "here.",
        "",
        "Jill: Just the other day, I saw this",
        "'Committee' judge bitching over what",
        "some girl was wearing to the store.",
        "Jill: No matter what you say, these",
        "people don't exist solely to entertain",
        "the public.",
        "Donovan: But this problem exists because",
        "they're the ones always cultivating the",
        "idea that they're perfect and untouchable.",
        "Donovan: Going to exotic locales, dressing",
        "in elegant ways, indulging in every luxury",
        "they can think of...",
        "Donovan: All that just leaves the public",
        "CRAVING for those little moments when they",
        "make a mistake and fall to their level!",
        "Jill: Can't say that's a lie, but...",
        "sometimes the crowd just wants to see",
        "they're human.",
        "Jill: 'Hey! That dude that plays the nice",
        "guy is indeed a really nice guy!'",
        "",
        "Jill: To be fair, the gossip articles don't",
        "help. Sensationalizing everything.",
        "",
        "Jill: It feels like they're instigating a",
        "behaviour that shouldn't even be",
        "acknowledged in the first place.",
        "Donovan: You like big words, eh brat?",
        "",
        "",
        "Donovan: Well, two can play that game of...",
        "",
        "",
        "Donovan: ...",
        "",
        "",
        "Jill: ...?",
        "",
        "",
        "Donovan: Hmhm...",
        "",
        "",
        "Donovan: Heeeeeey. You're a bartender,",
        "right?",
        "",
        "Jill: No, I'm a lab rat hellbent on world",
        "conquest.",
        "",
        "Donovan: Sarcasm wastes my time, my money,",
        "and your energy. Refrain from uing it.",
        "",
        "Donovan: Anyway, I just realised that a",
        "bartender like you must've heard quite a",
        "few stories in her career.",
        "Jill: (Talk about changing topics.)",
        "",
        "",
        "Jill: Maybe, why?",
        "",
        "",
        "Donovan: Wouldn't you like a column",
        "talking about those? I bet they would sell",
        "quite well.",
        "Jill: It would be like that priest who",
        "published 'Confessionary stories'... and",
        "then got excommunicated and lynched.",
        "Jill: People usually tell me all this stuff",
        "because they know I'm just a simple",
        "bartender...",
        "Jill: A personal stranger of sorts.",
        "",
        "",
        "Donovan: We could have you ghostwriting -",
        "half of our staff do that.",
        "",
        "Jill: They do?",
        "",
        "",
        "Donovan: You don't really think Lana",
        "Smithee is just one person, do you?",
        "",
        "Jill: (Figures.)",
        "",
        "",
        "Jill: A-Anyway...",
        "",
        "",
        "Jill: Eventually, the people from the",
        "stories would know it's them and blame",
        "me.",
        "Jill: Not only would it hurt us a a",
        "business, it would hurt me. I really like",
        "hearing clients rant about their lives.",
        "Jill: Oh... and it would hurt the clients",
        "too, I guess.",
        "",
        "Donovan: Well, if you ever retire, that",
        "offer is waiting for you.",
        "",
        "Jill: (Yeah, like you'll remember me two",
        "weeks from now.)",
        "",
        "Jill: Sure.",
        "",
        "",
        "Jill: Do you want another drink,",
        "Mr. Donovan?",
        "",
        "Donovan: Mister Donovan...",
        "",
        "",
        "Donovan: Mister... Donovan...",
        "",
        "",
        "Jill: D-did I say something wrong?",
        "",
        "",
        "Donovan: Not at all. I just really like",
        "the sound of that.",
        "",
        "Donovan: Mister Donovan... MISTER",
        "Donovan...",
        "",
        "Jill: Is it really that special?",
        "",
        "",
        "Donovan: At work, everyone calls me",
        "Mr. Dawson or Boss.",
        "",
        "Donovan: Boss is just a title. It's",
        "too impersonal and cold.",
        "",
        "Jill: (It is?)",
        "",
        "",
        "Donovan: Mr. Dawson was my father and",
        "grandfather. It's too general. But Mr.",
        "Donovan... Now that's more like it.",
        "Donovan: They're reffering to ME. To the",
        "man in front of them. Not to my family.",
        "Not to my position as boss. To ME.",
        "Jill: Do you want your employees to get",
        "personal with you, Mr. Donovan?",
        "",
        "Donovan: Oh, gods no. But I want them to",
        "fear ME. Not because I'm their boss or the",
        "name appearing in their paychecks...",
        "Donovan: ...but rather because I strike",
        "mortal dread into them.",
        "",
        "Donovan: Starting tomorrow, I'm going to",
        "make everyone call me that.",
        "",
        "Donovan: Oh yeah, you were asking",
        "something. What was it?",
        "",
        "Jill: Drink. Another one. Do you?",
        "",
        "",
        "Donovan: Ah yes, yes...",
        "",
        "",
        "Donovan: You know what? Third time's the",
        "charm. Gimme a Beer.",
        "",
        "Jill: Alright.",
        "",
        "",

        "",
        "",
        "",
        "Third time's the charm... for what?",
        "Anyway, better get him that beer.",
        "",

        "Jill: Here.",
        "",
        "",
        "Donovan: ...",
        "",
        "",
        "Donovan: I feel like calling the manager",
        "over this slop, but I'm on my way out so",
        "let's leave it at that.",
        "Jill: (Phew...)",
        "",
        "",

        "Jill: Here you go.",
        "",
        "",
        "Donovan: You know, even a blind man could",
        "see this isn't a fucking Beer.",
        "",
        "Donovan: Whatever. At least you had the",
        "decency to put alcohol in it.",
        "",
        "Jill: ...",
        "",
        "",

        "Jill: One Beer.",
        "",
        "",
        "Donovan: Yeah, I guess this one's good",
        "enough for now.",
        "",
        "Jill: Good to hear.",
        "",
        "",

        "Jill: One Beer.",
        "",
        "",
        "Donovan: Here's hoping I don't pass out.",
        "Cheers!",
        "",
        "Jill: Enjoy.",
        "",
        "",


        "Jill: Mr. Donovan, can I ask you",
        "something?",
        "",
        "Donovan: Depends on what you're going",
        "to ask. Is it about how to be successful?",
        "",
        "Donovan: Because I'll only spout stuff",
        "from those shitty 'how to get rich'",
        "books.",
        "Jill: No, it's not that... well, not",
        "exactly. How did you start in this business?",
        "",
        "Donovan: The Augmented Eye was a really",
        "important newspaper in Neo-San Francisco",
        "almost 10 years ago.",
        "Donovan: But... There was a big mess",
        "involving the head editor being",
        "defenestrated.",
        "Donovan: One thing led to another, and",
        "during a tough financial spot, I bought",
        "the whole thing and became a chief editor.",
        "Donovan: Neo-SF is still the HQ, but",
        "most of the revenues come from here.",
        "",
        "Donovan: Just being in Glitch City means",
        "at least 30% extra earnings.",
        "",
        "Jill: Oh yeah, I remember the news. It",
        "was quite a mess.",
        "",
        "Jill: And what made you pick a news",
        "website as business?",
        "",
        "Donovan: It sounded fun. I decided it",
        "on a whim - I might as well have ended up",
        "with a hairdressing chain called Marcelo.",
        "Donovan: Anyway, I've got to go. Are all",
        "the orders paid for?",
        "",
        "Jill: Yeah, thank you very much. Please",
        "come again.",
        "",
        "Donovan: Yeah, yeah...",
        "",
        "",

        "Donovan: Say kid, does this bar have any",
        "investors?",
        "",
        "Jill: (He didn't call it a hell hole?)",
        "",
        "",
        "Jill: There was some bloke named Sven",
        "that wanted to give us money if we",
        "stamped his face all over the place.",
        "Jill: But aside from that, no.",
        "",
        "",
        "Jill: These bars are pretty much like",
        "any fast food chain, so there are no",
        "local investors.",
        "Jill: Why?",
        "",
        "",
        "Donovan: Just wanted to let you know",
        "how lucky you bastards are.",
        "",
        "Donovan: Investors suck harder than",
        "my first wife's mouth.",
        "",
        "Donovan: These bastards think they're",
        "soooooooooo important because they put",
        "their money in the company.",
        "Jill: Well that's...",
        "",
        "",
        "Donovan: I mean, you give me money so you",
        "can make more. Let me do my thing and I'll",
        "give you your money!",
        "Donovan: But noooooooo, they have to stick",
        "their noses and start changing the silliest",
        "of stuff.",
        "Donovan: What good is it to be the boss if",
        "you still have to work for someone else?!",
        "",
        "Jill: You still have to answer to unions,",
        "the government, and those kinds of",
        "organizations, don't you?",
        "Donovan: Yeah, but that's paperwork. I",
        "make somebody else do it and call it a",
        "day. These losers ask for 'meetings'.",
        "Donovan: They start talking about stuff",
        "they don't like, stuff they found",
        "offensive...",
        "Donovan: And there's always that one guy",
        "or gal that says 'Hey, why don't you do",
        "what that other newspaper does?'",
        "Donovan: Recently they told me that they",
        "needed more clicks. MORE CLICKS!",
        "",
        "Donovan: I make sure to keep stuff spicy",
        "while still keeping production quality up",
        "but it's never enough for them!",
        "Donovan: Well, you know what?! They want",
        "more clicks? I'LL GIVE THEM MORE CLICKS!",
        "",
        "Donovan: I'll show them what happens when",
        "I do what they want and don't reject",
        "ideas.",
        "Donovan: They'll know who the hell",
        "DONOVAN D. DAWSON is.",
        "",
        "Jill: Should I be worried? Nah...",
        "",
        "",
        "Jill: (At least he payed before storming",
        "off.)",
        "",
        "Jill: (I wonder what happened with Sven",
        "though. We never heard from him again.)",
        "",

        "Donovan: But I need to cut myself off - I",
        "just remembered I have a night shift later.",
        "",
        "Donovan: Give me something bitter... and",
        "big, but not alcoholic. I need to wake",
        "myself up.",
        "Jill: I can do that.",
        "",
        "",

        "",
        "",
        "",
        "Something bitter, big, and with no",
        "alcohol at all. Alright.",
        "",
        "Jill: Here.",
        "",
        "",
        "Donovan: ...",
        "",
        "",
        "Donovan: Brat, do you need glasses? I",
        "think our perception of what constitutes",
        "'big' is clearly very different.",
        "Jill: ...",
        "",
        "",

        "Jill: Here you go.",
        "",
        "",
        "Donovan: Paint me blue and call me Sue, you",
        "can actually do it.",
        "",
        "Donovan: This'll help me stay up late",
        "tonight...",
        "",

        "Jill: Here.",
        "",
        "",
        "Donovan: Yes, this doesn't have alcohol,",
        "but it's also not what I asked for. What's",
        "your problem?",
        "Jill: (Don't retort. He's right.)",
        "",
        "",

        "Jill: Here.",
        "",
        "",
        "Donovan: *sniff*",
        "",
        "",
        "Donovan: Kid, I just said I needed to",
        "stop the alcohol, not that i needed more.",
        "",
        "Jill: Sorry, force of habit.",
        "",
        "",


        "Gillian: JIIIIIIIIIIIIIILL!!!",
        "",
        "",
        "Jill: Yes?",
        "",
        "",
        "Gillian: What the hell happened in",
        "that bathroom?",
        "",
        "Gillian: That kind of mess usually",
        "requires you to have THUMBS!",
        "",
        "Jill: Crafty dogs, I tell you. You'd",
        "think their short legs would hinder them.",
        "",
        "Gillian: T-The ceiling... the sinks...",
        "the toilets... THE VENTS!",
        "",
        "Jill: Shh... you'll wake up Briar Rose",
        "over there.",
        "",
        "Gillian: I. Won't. Forget this!",
        "",
        "",
        "Jill: Yeah, yeah...",
        "",
        "",
        "Jill: Oh, a client.",
        "",
        "",
        "Jill: Welcome to Valhalla, what can I...",
        "",
        "",

        "???: Big Gut Punch. Fast.",
        "",
        "",
        "Jill: ...alright.",
        "",
        "",

        "",
        "",
        "",
        "He wants a Gut Punch. I wanna give him",
        "a gut punch, alright.",
        "",
        
        "Jill: Here.",
        "",
        "",
        "???: Not my order.",
        "",
        "",
        "???: Don't expect me to pay for something",
        "I didn't order.",
        "",
        "???: You're lucky I'm in a dire need of",
        "getting drunk.",
        "",
        "Jill: ...",
        "",
        "",

        "Jill: Here you are.",
        "",
        "",
        "???: What's this?",
        "",
        "",
        "Jill: Something sweet.",
        "",
        "",
        "???: But I didn't order this.",
        "",
        "",
        "Jill: I just felt like you needed this.",
        "",
        "",
        "???: ...",
        "",
        "",
        "???: ...alright. I'll take it.",
        "",
        "",

        "Jill: Here.",
        "",
        "",
        "???: Hm, you can actually do it then.",
        "",
        "",
        "???: ...",
        "",
        "",

        "???: Hmph... this crackhouse is a bar?",
        "",
        "",
        "Jill: (Hell hole, crackhouse...)",
        "",
        "",
        "???: It smells like dog urine and soap.",
        "How the hell do you expect someone to",
        "feel comfortable in here?",
        "Jill: I'm surprised you decided to come",
        "to our little 'crackhouse' at all,",
        "mister...",

        "???: What the hell do you care?",
        "",
        "",
        "Jill: (The payment registry says...)",
        "",
        "",
        "Jill: Sorry for the question then,",
        "Mr. Ingram McDougal.",
        "",
        "Ingram: ...",
        "",
        "",

        "Ingram: Ingram. Ingram McDougal.",
        "",
        "",

        "Jill: Sorry about the smell, we're working",
        "on fixing it. There was an... accident",
        "over the weekend.",
        "Ingram: But it's Tuesday.",
        "",
        "",
        "Jill: ...",
        "",
        "",
        "Jill: Please... let me know what I can do",
        "to make your experience more pleasant",
        "regardless.",
        "Ingram: If I pay you, will you come with",
        "me to a motel for a couple of hours?",
        "",
        "Jill: No.",
        "",
        "",
        "Ingram: Then I have no use for you",
        "beyond giving me drinks.",
        "",
        "Jill: (Such pleasant clientele tonight.)",
        "",
        "",
        "Jill: May I ask why you decided to come",
        "to our bar then?",
        "",
        "Ingram: Somebody recommended me this place",
        "and I have absolutely no idea why she",
        "likes it.",
        "Ingram: She says she's a regular here and",
        "all. I'm starting to doubt her tastes.",
        "",
        "Jill: A regular? Can I ask who?",
        "",
        "",
        "Ingram: No.",
        "",
        "",
        "Jill: ...",
        "",
        "",
        "Ingram: I'll concede one thing: whoever",
        "picks the music at least has decent",
        "taste.",
        "Dana: Hay Jill, where did you put the",
        "dish soap? Gil's run out.",
        "",
        "Jill: Below the sink where it's always",
        "been.",
        "",
        "Dana: Right.",
        "",
        "",
        "Dana: Oh! A customer. Good evening, sir.",
        "Hope you enjoy your stay at Valhalla.",
        "",
        "Jill: So, any other feedback you want to",
        "provide the establishment so we can enhance",
        "your customer experience?",
        "Ingram: No... nothing.",
        "",
        "",
        "Jill: That's... an interesting change of",
        "heart.",
        "",
        "Ingram: I can't afford to slander this",
        "place knowing SHE's here!",
        "",
        "Jill: You know my boss?",
        "",
        "",
        "Ingram: I don't *know* here, but i know",
        "who she is.",
        "",
        "Ingram: Dana Zane, the Red Comet.",
        "",
        "",
        "Ingram: The woman who fended off mall",
        "rioters all by herself, knocking them out",
        "cold one by one.",
        "Jill: That's... an achievment and a title",
        "I've never heard before.",
        "",
        "Jill: I know Boss did quite a few things",
        "before opening this bar, but that",
        "sounds...",
        "Jill: Would you happen to know how she",
        "got her mechanical arm?",
        "",
        "Ingram: I heard a couple of stories but",
        "they sound too fantastical to be true.",
        "",
        "Ingram: ...",
        "",
        "",
        "Jill: You've had an interesting change",
        "of attitude.",
        "",
        "Ingram: I saw that woman take out",
        "armed rioters with her bare hands.",
        "",
        "Ingram: Once you see something like",
        "that, it's hard not keep your mouth shut",
        "in front of them.",
        "Jill: Interesting...",
        "",
        "",
        "Jill: You can relax, though. I've only seen",
        "her deal with clients personally about two",
        "or three times.",
        "Jill: One involved Class-5 weaponry, the",
        "other one a 'pick-up artist', and the",
        "latest had an alpaca.",
        "Ingram: An alpaca?",
        "",
        "",
        "Jill: Not really an alpaca, but...",
        "",
        "",
        "Jill: There's this woman that owns a",
        "textile company.",
        "",
        "Jill: She got really drunk and... she",
        "started screaming she was an alpaca.",
        "",
        "Jill: She started spitting on everything",
        "afterwards. My boss had to show her the",
        "exit.",
        "Jill: I'd rather not remember that night,",
        "so let's leave it at that.",
        "",

        "Jill: Can I get you anything else?",
        "",
        "",
        "Ingram: Give me a Piledriver, please.",
        "",
        "",
        "Jill: (Please? There's a word I haven't",
        "heard today.)",
        "",
        "Jill: Coming right up.",
        "",
        "",

        "",
        "",
        "",
        "He wants a Piledriver. I honestly feel like",
        "suplexing him, though.",
        "",

        "Ingram: This is not what I asked for.",
        "",
        "",
        "Jill: You look stressed from seeing my",
        "boss. Sweet drinks can help with that.",
        "",
        "Ingram: ...fine.",
        "",
        "",

        "Ingram: You know, all these sweet drinks",
        "remind me of my ex-wife.",
        "",
        "Jill: How so?",
        "",
        "",
        "Ingram: Whenever she saw me in a foul mood,",
        "she'd take a andy out of her purse and",
        "give it to me.",
        "Ingram: Then she'd smile and say something",
        "about sweet stuff helping.",
        "",
        "Jill: Sounds like a nice woman.",
        "",
        "",
        "Ingram: She was nice up until we had our",
        "daughter. A couple of weeks after she gave",
        "birth, she just up and ran away.",
        "Ingram: Left a nite about everything being",
        "too real or something like that.",
        "",
        "Jill: This is my serving you sweet drinks",
        "resurrecting bad memories?",
        "",
        "Ingram: Not really. The good times I spent",
        "with her won't go away even if she acted",
        "like a bitch in the end.",

        "Ingram: This isn't a Piledriver.",
        "",
        "",
        "Jill: It's a local drink. My coworker",
        "came up with it. He calls it a Suplex.",
        "",
        "Ingram: It isn't gonna blow up in my face,",
        "is it?",
        "",
        "Jill: No, it's safe. It's even been added",
        "to the BTC's official recipe book.",
        "",
        "Ingram: Good.",
        "",
        "",

        "Jill: Here.",
        "",
        "",
        "Ingram: Hm... it's fine, I guess.",
        "",
        "",

        "Ingram: ...",
        "",
        "",
        "Jill: (No retort? He seems a tad too",
        "submissive for me.)",
        "",

        "Ingram: Hey lady, have you ever faked",
        "an orgasm?",
        "",
        "Jill: ...",
        "",
        "",
        "Jill: I'm sorry, I think I heard wrong.",
        "",
        "",
        "Ingram: I asked if you've ever faked",
        "an orgasm.",
        "",
        "Jill: That's a question I'm not gonna",
        "answer.",
        "",
        "Ingram: I'll take that as a yes.",
        "",
        "",
        "Ingram: I was just thinking about how",
        "good a lie can be.",
        "",
        "Ingram: I mean, even the most sincere",
        "of people lie once in a while.",
        "",
        "Ingram: Lies can buy you time. Lies can",
        "make you happy...",
        "",
        "Ingram: Reality will come crashing through",
        "the door eventually. But for that moment",
        "the lie can give meaning to you.",
        "Jill: ...I say lies are like your porn",
        "stash.",
        "",
        "Jill: You know they exist but you shouldn't",
        "acknowledge them.",
        "",
        "Ingram: Does that mean you've really faked",
        "an orgasm? 'cause you look like you have a",
        "lot of experience.",
        "Jill: ...",
        "",
        "",
        "Jill: Still, that's quite a random thought",
        "to just suddenly have.",
        "",
        "Jill: Are you perhaps lying about something",
        "right now?",
        "",
        "Ingram: Not really, I was just thinking",
        "about people making polite comments about",
        "this crackhouse.",
        "Jill: *sigh* Of course you were.",
        "",
        "",

        "Ingram: Hey, I'm gonna need another drink",
        "here.",
        "",
        "Jill: Already? Don't you think you're",
        "drinking a bit quickly?",
        "",
        "Ingram: That's my problem, not yours.",
        "Give me a Fringe Weaver.",
        "",
        "Jill: Alright...",
        "",
        "",

        "",
        "",
        "",
        "Alright. Let's give him a Fringe Weaver.",
        "",
        "",

        "Ingram: And you think this'll make me",
        "happy or something?",
        "",
        "Jill: Yes.",
        "",
        "",
        "Ingram: ...",
        "",
        "",

        "Jill: Try not to drink it too fast.",
        "",
        "",
        "Ingram: That's up to me.",
        "",
        "",

        "Ingram: So because I'm drinking too fast,",
        "you're giving me something else? What",
        "am I? A kid?",
        "Jill: (A big one, yeah.)",
        "",
        "",

        "Ingram: Hey lady, have you ever felt empty?",
        "",
        "",
        "Jill: Empty how? Like, hungry?",
        "",
        "",
        "Ingram: No, I mean empty like there's a",
        "part of you missing.",
        "",
        "Jill: ...can't say I particularly have.",
        "",
        "",
        "Ingram: I just feel there's this part of",
        "myself that lacks something.",
        "",
        "Ingram: An urge to get or do something",
        "that I just can't satisfy.",
        "",
        "Jill: Have you tried taking up a hobby?",
        "",
        "",
        "Jill: It might now solve your problems,",
        "but it might keep you busy enough to",
        "avoid thinking about it.",
        "Ingram: Any suggestions?",
        "",
        "",
        "Jill: Well... collecting stuff, reading,",
        "bungee jumping, combat sports,",
        "exercising...",
        "Ingram: Sounds a lot cheaper than the",
        "alternative.",
        "",
        "Jill: Which is?",
        "",
        "",
        "Ingram: Bitches and alcohol.",
        "",
        "",
        "Ingram: I tried sex tourism once. It was",
        "like a bloody Russian roulette of STDs so",
        "I left midway through.",
        "Ingram: I once blew my christmas bonus",
        "hiring 3 women for an orgy... porn is",
        "more amusing and way cheaper.",
        "Ingram: I've also hired a girl to act",
        "like my daughter for a day for three",
        "years in a row now.",
        "Ingram: Nothing seems to do it.",
        "",
        "",
        "Jill: Um...",
        "",
        "",
        "Jill: ...have you tried rescuing",
        "a puppy?",
        "",
        "Ingram: You can't fuck puppies. At",
        "least you SHOULDN'T.",
        "",
        "Jill: I'm drawing a blank then. can't",
        "think of anything that might help.",
        "",
        "Ingram: I wasn't expecting you to help",
        "me... or to believe me.",
        "",
        "Jill: Eh?",
        "",
        "",
        "Ingram: I could've been lying through my",
        "teeth this whole time.",
        "",
        "Ingram: People lie, lady.",
        "",
        "",
        "Jill: ...",
        "",
        "",
        "Ingram: Anyway, I'm leaving now. This smell",
        "is killing me.",
        "",
        "Jill: Please come again.",
        "",
        "",
        "Ingram: Don't count on it.",
        "",
        "",
        "Jill: (Good.)",
        "",
        "",

        "Ingram: Hey lady, what's your opinion on",
        "the White Knights?",
        "",
        "Jill: Opinion? Can't say I have much of",
        "one.",
        "",
        "Jill: I haven't had enough encounters",
        "with the White Knights to form one",
        "myself.",
        "Ingram: What if I said one killed",
        "my daughter?",
        "",
        "Jill: ...",
        "",
        "",
        "Jill: Really?",
        "",
        "",
        "Ingram: It happened about four years ago.",
        "",
        "",
        "Ingram: She was just outside her school",
        "when a chase occurred between a psycho",
        "and some police squad or whatever.",
        "Ingram: She just so happened to be in",
        "the wrong place at the wrong time.",
        "",
        "Jill: What happened?",
        "",
        "",
        "Ingram: Sadly, nothing dramatic happened.",
        "Nothing like the psycho taking her hostage",
        "and the squad bulldozing through her.",
        "Ingram: The squad passed by her. One of",
        "the members hit her to move her out of",
        "the way.",
        "Ingram: She knocked her head against the",
        "wall when she fell. Killed her instantly.",
        "",
        "Jill: Damn...",
        "",
        "",
        "Ingram: How do you feel about them now?",
        "",
        "",
        "Jill: ...don't take this the wrong way,",
        "but nothing's changed, really.",
        "",
        "Jill: I haven't interacted with enough",
        "White Knights to form an opinion of",
        "my own.",
        "Jill: If I started judging groups based",
        "on only a few examples, I'd be against all",
        "Lilim because one of them went rogue.",
        "Ingram: Yeah. To be fair, I'm in the same",
        "boat.",
        "",
        "Jill: Eh?",
        "",
        "",
        "Ingram: I wasn't looking for retaliation",
        "against White Knights. Just the faggot that",
        "killed her.",
        "Ingram: So, I spent some money to get the",
        "name of the bastard and then some more",
        "money to have him killed.",
        "Ingram: The guy I sent brought me his head",
        "as proof and a cycle was closed...",
        "",
        "Ingram: ...or at least that's what I tell",
        "myself everyday.",
        "",
        "Jill: Hm?",
        "",
        "",
        "Ingram: On one hand, I feel satisfaction",
        "knowing that guy is dead.",
        "",
        "Ingram: On the other, I feel... empty.",
        "",
        "",
        "Ingram: The hate I felt for that guy,",
        "the sadness for my daughter... all of",
        "it gone.",
        "Ingram: I spent so much time irate that",
        "it kinda burned away any feelings of",
        "sadness.",
        "Jill: I guess I know how that feels.",
        "",
        "",
        "Jill: Sometimes, something happens and I",
        "know I should feel mad or sad, but I can't",
        "muster it. And it worries me.",
        "Ingram: I've tried to see if I can stir",
        "some feelings into myself.",
        "",
        "Ingram: For the past three years, I've",
        "hired this girl to dress up and act like",
        "my daughter for a day.",
        "Ingram: She even arrives at the time she",
        "would've come back from school.",
        "",
        "Ingram: For as long as the day lasts, she",
        "makes me feel like I should take care of",
        "her...",
        "Ingram: But at the end of the day, when",
        "she's gone...",
        "",
        "Ingram: I feel nothing. Nothing at all.",
        "",
        "",
        "Ingram: I just wanna be able to cry for",
        "my dead daughter. Is that so much to ask?",
        "",
        "Jill: Maybe you shouldn't force yourself.",
        "",
        "",
        "Jill: Emotions will rush in when you least",
        "expect it, and mourning doesn't necessarily",
        "involve lots of tears.",
        "Ingram: Yeah, maybe I should try that",
        "sometime.",
        "",
        "Ingram: Although, you know I could've been",
        "lying my heart out, right?",
        "",
        "Jill: Huh?",
        "",
        "",
        "Ingram: Everything I just said. It could've",
        "been a big fat lie on my end.",
        "",
        "Jill: ...",
        "",
        "",
        "Ingram: I could've also have lied about",
        "lying.",
        "",
        "Ingram: People lie, lady. Never forget",
        "that.",
        "",
        "Ingram: Now if you'll excuse me...",
        "",
        "",
        "Jill: Please come again.",
        "",
        "",
        "Ingram: Don't count on it.",
        "",
        "",
        "Jill: (I won't, don't worry.)",
        "",
        "",

        "Jill: Phew...",
        "",
        "",
        "Jill: Boss, I'm gonna take my break!",
        "",
        "",
        "Dana: Alright.",
        "",
        "",

        "And with that, this little demo comes",
        "to an end.", 
        "",
        "Please contact me if you've",
        "found inconsistencies with the",
        "original game.",
        "",
        "",
        "",
        "",
        "",
        "",
        "Restart the ROM",
        "",
        "",
    };

    constexpr const char* lines_2[] = 
    {
        "At least I didn't get locked up",
        "this time.",
        "",
        "[JUKEBOX]",
        "",
        "",
        "[JUKEBOX]",
        "",
        "",

        "Jill: Okay then. Back in ation!",
        "",
        "",
        "???: Good evening!",
        "",
        "",
        "Jill: Good eve-...",
        "",
        "",
        "Jill: ...",
        "",
        "",
        "Jill: Um... would you mind taking your",
        "helmet off?",
        "",
        "???: Oh? Sorry. It's so comfortable I",
        "usually forget I have it on.",
        "",
        "",
        "",
        "",
        "???: Is this better?",
        "",
        "",
        "Jill: Yeah, thank you.",
        "",
        "",
        "Jill: What can I get you, miss...?",
        "",
        "",
        "???: Master Specialist, Sei P. Asagiri of",
        "the 765th Division Valkyrie Corps at",
        "you service!",
        "Sei: Wait... that's too long. Just",
        "call me Sei.",
        "",
        "Jill: What can I get for you, Sei?",
        "",
        "",
        "Sei: Let's see... I'm in the mood for a",
        "sweet drink. Oh! But not 'sweet' as in",
        "'cool'...",
        "Sei: ...although a cool drink would be",
        "nice too. Um... but not 'cool' as in",
        "'great' and especially not as in 'big'.",
        "Sei: More so since I have to get up early",
        "tomorrow and I can't afford to have a",
        "hangover.",
        "Sei: Um... sorry, did you get that?",
        "",
        "",
        "Jill: A sweet drink. Preferably a cold one",
        "that's not too big. Right?",
        "",
        "Sei: Yeah! That's it!",
        "",
        "",
        "Jill: I can do that. Give me a sec.",
        "",
        "",

        "",
        "",
        "",
        "Something small, sweet, and icy.",
        "I wonder if I have something so",
        "specific.",

        "Jill: Here.",
        "",
        "",
        "Sei: I-is this what you call a not-big",
        "drink? Perhaps I need to work on my",
        "tolerance?",
        "Jill: *ahem*",
        "",
        "",

        "Jill: Here you are.",
        "",
        "",
        "Sei: Umm... didn't you have anything sweet?",
        "",
        "",
        "Sei: Although I guess my idea of sweet",
        "could be different from yours.",
        "",
        "Sei: Nevermind, this works fine too.",
        "",
        "",

        "Jill: Here.",
        "",
        "",
        "Sei: Um...",
        "",
        "",
        "Sei: I expected something with ice, but",
        "this is good enough.",
        "",

        "Jill: Here you are.",
        "",
        "",
        "Sei: Aaaaaah yes, this is just what I",
        "needed. Thanks!",
        "",

        "Jill: We don't get many Whaite Knights as",
        "clients. I can only remember one other,",
        "in fact.",
        "Jill: You said you're from the Valkyrie",
        "corps, right? Are you the guys who deal",
        "with riots and such?",
        "Sei: Riots...? Oh! Nonono... You're",
        "thinking the Blitzkrieg corps. The ones",
        "with huge plated suits, right?",
        "Jill: Yeah, those.",
        "",
        "",
        "Sei: No, we're different people. I",
        "mean... obviously we're different people.",
        "But we don't deal with riots or anything.",
        "Sei: In fact, you could say we deal with",
        "their aftermath.",
        "",
        "Jill: How so?",
        "",
        "",
        "Sei: 'To rescue, heal, and protect! We are",
        "the angels who soothe those suffering enemy",
        "attack!'",
        "Sei: 'We are the light of hope in the",
        "darkest of times, the ones who assist the",
        "victims of crime!'",
        "Sei: 'We watch, we protect.'",
        "",
        "",
        "Jill: Um... what was that?",
        "",
        "",
        "Sei: Sorry, it's sort of our pledge of",
        "allegiance; we recite it every morning.",
        "",
        "Sei: What it means is that our duties",
        "are mostly rescuing civilians, healing the",
        "injured, and protecting them from... stuff.",
        "Jill: What kind of stuff?",
        "",
        "",
        "Sei: Burglars, rapists, car crashes,",
        "anything that might happen on our",
        "watch.",
        "Jill: You mentioned 'heal'. Are you",
        "a doctor then?",
        "",
        "Sei: Nah. I know many doctors, but I'm not",
        "one. I'm more of a paramedic. I treat people",
        "so they can arrive safely at a doctor.",
        "Sei: I'm also kinda like a firefighter in",
        "that i sometimes rescue people from",
        "places.",
        "Jill: Damn, that must be a tough job.",
        "",
        "",
        "Sei: Sort of, but it's also really",
        "rewarding.",
        "",
        "Sei: I mean, I've yet to see somebody that",
        "ISN'T glad to see me when I arrive.",
        "",
        "Jill: You must've seen some shocking sights.",
        "",
        "",
        "Sei: Yeah! This one time, when I was",
        "saving some people from the top of a",
        "collapsing building...",
        "Sei: I looked down and was blown away by",
        "how pretty the city was! It was like a",
        "starry sky on earth!",
        "Sei: Oh! And there was this time we were",
        "cleaning up the aftermath of a car crash.",
        "Water was pouring out of a hydrant.",
        "Sei: With the lights and scattered pieces",
        "of glass, it was almost dream-like.",
        "",
        "Jill: T-that's not what I meant by",
        "'shocking sights'.",
        "",
        "Sei: No? But those are sights... and",
        "they're shocking, right?",
        "",
        "Jill: Yeah, but... nevermind.",
        "",
        "",
        "Sei: Wait... did I mishear and you",
        "actually meant 'sighs'?",
        "",
        "Sei: I mean, sure.",
        "",
        "",
        "Sei: I've suffered the deepest, longest",
        "and most frustrated sighs from people",
        "after everything's said and done, but...",
        "Jill: Don't worry, you didn't mishear. I",
        "guess I was just expecting a different",
        "kind of answer.",
        "Sei: What kind of answer?",
        "",
        "",
        "Jill: Don't... worry too much about it.",
        "",
        "",
        "Jill: You finished your drink - can I get",
        "you anything else?",
        "",
        "Sei: Hm... Something classy. A classy",
        "drink.",
        "",
        "Jill: Can you be more specific?",
        "",
        "",
        "Sei: Don't make it too big. Does that work?",
        "",
        "",
        "Sei: Sorry, I don't come to bars very often.",
        "My drinks usually come in a can.",
        "",
        "Jill: No problem. Don't worry. A classy",
        "drink, right? Let's see what I can find",
        "for you.",

        "",
        "",
        "",
        "A classy drink. Simple enough.",
        "",
        "",

        "Jill: Here.",
        "",
        "",
        "Sei: Hm... I don't know...",
        "",
        "",
        "Sei: This doesn't look like the kind of",
        "stuff Stella would drink.",
        "",
        "Jill: Who?",
        "",
        "",
        "Sei: Oh, Stella's my best friend.",
        "",
        "",
        "Sei: I don't like using the 'best' tag,",
        "but there's no other way to refer to her,",
        "you know?",
        "Jill: I see.",
        "",
        "",

        "Jill: Here you are.",
        "",
        "",
        "Sei: Yup, this looks like something",
        "Stella would drink.",
        "",
        "Jill: Who?",
        "",
        "",
        "Sei: She's my dearest friend. Not that I",
        "don't have any others, but she's the one",
        "I've known the longest.",
        "Sei: She likes these kinds of drinks, so I",
        "wanted to see what's so special about them.",
        "",
        "Jill: And what do you think?",
        "",
        "",
        "Sei: I was expecting something... stronger.",
        "I like it quite a bit.",
        "",

        "Sei: Say, Miss Bartender, what's your name?",
        "",
        "",
        "Jill: Hm?",
        "",
        "",
        "Sei: You know my name, now I wanna know",
        "yours.",
        "",
        "Jill: Oh sure, just call me Jill.",
        "",
        "",
        "Sei: Jill... hm... Jill...",
        "",
        "",
        "Sei: Jill is short for... Jillian! No,",
        "that's not right.",
        "",
        "Jill: ...",
        "",
        "",
        "Sei: Jillian... Ju... Julianne!",
        "",
        "",
        "Jill: Do. NOT. Call me Julianne, please.",
        "",
        "",
        "Sei: ...!",
        "",
        "",
        "Jill: ...",
        "",
        "",
        "Jill: *sight* Sorry about that.",
        "",
        "",
        "Sei: No, please excuse me. I didn't want",
        "to anger you.",
        "",
        "Sei: Um... But why don't you like being",
        "called by your full name?",
        "",
        "Jill: It's a stupid reason. Don't dwell",
        "too much on that.",
        "",
        "Sei: Oh, ok. I still feel bad about",
        "angering you, though.",
        "",
        "Jill: Why?",
        "",
        "",
        "Sei: Because you look like a nice girl,",
        "Jill, and I don't like angering nice",
        "people.",
        "Sei: If it helps somehow, I really like",
        "this place.",
        "",
        "Jill: That... actually helps. You're the",
        "first person to say something nice today,",
        "thanks.",
        "Jill: What do you like about it?",
        "",
        "",
        "Sei: The smell of dog urine and soap!",
        "",
        "",
        "Jill: ...",
        "",
        "",
        "Sei: My mom used to be a veterinarian, and",
        "I used to go to her clinic after school, so",
        "the smell takes me back.",
        "Sei: It makes me feel... comfy and",
        "nostalgic.",
        "",
        "Jill: *ahem* What made you become a White",
        "Knight instead of a veterinarian or...",
        "anything else?",
        "Sei: Well, I was never a good student, so",
        "studying medicine of any kind was out of",
        "the question.",
        "Sei: That aside, it's mostly because of",
        "something that happened while I was a kid.",
        "",
        "Sei: A White Knight attacked my friend",
        "and was coming for me when this other",
        "White Knight saved us.",
        "Sei: I don't remember what happened next.",
        "I just woke up in a hospital with my friend",
        "watching over me.",
        "Sei: I mean, it wasn't a prophetic moment",
        "or anything like that. But ever since then",
        "I felt this was my calling.",
        "Sei: That I wanted to help people the same",
        "way they helped me.",
        "",
        "Jill: Huh... it's interesting though: one",
        "would think being attacked by a White",
        "Knight would make you run away from them.",
        "Sei: Yeah, but it was another one that",
        "saved me.",
        "",
        "Sei: So I kinda guide myself toward",
        "judging everything on an individual",
        "basis.",
        "Sei: Well, not to an extremist extent,",
        "but... you get me.",
        "",
        "Jill: Yeah. I try to do the same too.",
        "",
        "",
        "Jill: Why join the Valkyrie corps",
        "specifically, though?",
        "",
        "Sei: Because I wanted to rescue people",
        "from dire situations whenever",
        "possible.",
        "Sei: And going into patrols and all",
        "that felt too tiresome.",
        "",
        "Sei: It's also the one with the least",
        "paperwork involved.",
        "",
        "Jill: Now that I think about it, there",
        "are different kinds of White Knights,",
        "right?",
        "Sei: I gues 'White Knight' is too broad",
        "a term.",
        "",
        "Sei: There's not one specific type -",
        "there are many different classes.",
        "Rescue, assault...",
        "Sei: There's even a squad full of",
        "bureaucrats.",
        "",
        "Jill: Really?",
        "",
        "",
        "Sei: Yeah, they get assigned to",
        "companies to handle the accounting and",
        "that kind of stuff.",
        "Sei: People usually ask for them because",
        "they speed up processes.",
        "",
        "Sei: But a few are assigned when a company",
        "is suspected of having weird,",
        "under-the-table deals.",
        "Jill: Interesting.",
        "",
        "",
        "Sei: There's also a squad dedicated to",
        "fighting school bullying.",
        "",
        "Sei: They were doing a nice job, but a",
        "'fad' of anti-bullying campaigns passed",
        "and they lost their funding.",
        "Sei: I believe some members still work",
        "with anti-bullying cases in an unofficial",
        "capacity.",
        "Jill: That'd be nice... I think.",
        "",
        "",
        "Jill: Can I get you anything else?",
        "",
        "",
        "Sei: I don't know if I should. I can't",
        "afford that many drinks. And besides, I",
        "don't know how much alcohol I can handle.",
        "Jill: Yeah, I can see that.",
        "",
        "",

        "Sei: Yup, I'm gonna stop here today. Thanks",
        "for the chat, Jill.",
        "",
        "Jill: Sure, no problem.",
        "",
        "",
        "Sei: Bye!",
        "",
        "",
        "Jill: Come again.",
        "",
        "",
        "Sei: Will do!!",
        "",
        "",
        "Jill: Wait! You forgot your...",
        "helmet.",
        "",
        "Jill: She's gone...",
        "",
        "",
        "Jill: Whoa!",
        "",
        "",
        "Jill: Gil, did the ammonia make you go",
        "nuts?!",
        "Gillian: There was this time in Zanzibar",
        "when that almost happened. In any case,",
        "I'll go check that noise.",
        "",

        "Sei: Oh, you know what? I'll have something",
        "else.",
        "",
        "Sei: I remember some drink called a...",
        "Martini?",
        "",
        "Jill: Branditini.",
        "",
        "",
        "Sei: No, I'm pretty sure it's Martini.",
        "",
        "",
        "Jill: It's Branditini, trust me. I'll",
        "get you one.",
        "",

        "",
        "",
        "",
        "She wants a Martin-... sorry,",
        "a Branditini.",
        "",

        "Jill: Here.",
        "",
        "",
        "Sei: See? I told you it was a Martini.",
        "This one doesn't look anything like",
        "what I had in mind.",
        "Sei: But I'll try it, anyway.",
        "",
        "",

        "Jill: Here, see?",
        "",
        "",
        "Sei: Huh, you were right.",
        "",
        "",
        "Sei: Thanks!",
        "",
        "",

        "Sei: Hey Ji... Ji... *yawn*. Hey Jill...",
        "wanna hear something funny?",
        "",
        "Jill: Sure.",
        "",
        "",
        "Sei: There's this... guy named Jack, he's",
        "the captain of one of the Blitz.. zzzkrieg",
        "Corps.",
        "Sei: His squad is... *yawn* filled with",
        "suits he customized himself.",
        "",
        "Sei: They're all themed after su...",
        "sssuits of *yawn* suits of cards.",
        "",
        "Sei: Heh... suits of suits.",
        "",
        "",
        "Sei: His armor is particularly flambo...",
        "flam... gaudy. His visor has a rainbow",
        "and he wears a cape.",
        "Sei: His 'Jacker Blietzkrieg Corps' are",
        "the joke of the whole... the...",
        "whole...",
        "Sei: ...",
        "",
        "",
        "Jill: ...?",
        "",
        "",
        "Sei: ...zzzzzzz.",
        "",
        "",
        "Jill: Wow...",
        "",
        "",
        "Jill: Anyway, I better call a cab and-",
        "",
        "",
        "Sei: TROUBLE!",
        "",
        "",
        "Jill: ...and now, I don't need to call",
        "a cab.",
        "",
        "Jill: Oh... but it looks like I'll be",
        "holding her helmet until she realizes",
        "she left it here.",
        "Gillian: I'll go check that noise! If you",
        "hear me scream, lock down the bar!",
        "",
        "Jill: Careful.",
        "",
        "",

        "Sei: You know what? I think I'll bring",
        "a friend of mine here in a couple",
        "of days.",
        "Jill: Really? Why?",
        "",
        "",
        "Sei: I like the feel of this place and",
        "I want to share it with her.",
        "",
        "Sei: It might be a bit difficult, though.",
        "She's more into, um... classier places.",
        "",
        "Sei: N-not that this place isn't nice!",
        "B-But...",
        "",
        "Jill: Don't worry, I know the kind of place",
        "I work in.",
        "",
        "Sei: I-I see...",
        "",
        "",
        "Sei: But it shouldn't be too bad, I just",
        "need to-",
        "",
        "Sei: What was that?!",
        "",
        "",
        "Jill: Sounded like an explosion.",
        "",
        "",
        "Sei: I'd better check that. I paid you",
        "already, right?",
        "",
        "Jill: Yeah, go ahead. Be careful.",
        "",
        "",
        "Sei: I will!",
        "",
        "",
        "Jill: She... left her helmet.",
        "",
        "",
        "Jill: (Well, if she's coming back, I'll",
        "just hold it for her.)",
        "",
        "Gillian: I'll go check what the everloving",
        "hell that explosion was.",
        "",
        "Jill: Careful.",
        "",
        "",

        "???: What...?",
        "",
        "",
        "Jill: (Oh, she woke up.)",
        "",
        "",
        "???: W-Where am I? Where am I?!",
        "",
        "",
        "Jill: Good evening and welcome",
        "to Valhalla.",
        "",
        "Jill: (That might not have been the",
        "best thing to say.)",
        "",
        "???: V-Valhalla? Am I dead?",
        "",
        "",
        "???: D-Does that mean that Incle Ingus'",
        "ramblings about the afterlife looking like",
        "a shoddy downtown bar are true?",
        "Jill: (Called it!)",
        "",
        "",
        "Jill: Afterlife?",
        "",
        "",
        "???: I'm not dead?",
        "",
        "",
        "Jill: As far as I can tell? No.",
        "",
        "",
        "Jill: To be fair, I don't know how death",
        "or the afterlife work exactly, but you're",
        "breathing, right?",
        "???: ...!!",
        "",
        "",
        "???: ...",
        "",
        "",
        "???: ...alright, then where the hell am I?",
        "",
        "",
        "???: How did I get here?! Who brought me",
        "here?! What were you planning to do with",
        "me?!",
        "???: Are you organ traffickers?! Robbers?!",
        "Rapists?! Pickpockets?! You're pickpockets,",
        "aren't you?!",
        "???: W-W-Why aren't you saying anything?!",
        "",
        "",
        "Jill: I'm waiting for you to vent your",
        "worries. Otherwise you'll just...",
        "",
        "???: You're rapists, aren't you?!",
        "RAPISTS! THE WHOLE LOT OF YOU!!",
        "",
        "???: You wanna tear my clothes, beat me",
        "unconscious, have your horrible way with me",
        "and then brutally murder me, don't you?!",
        "???: All while still violating every hole",
        "in my body as I lay there twitching,",
        "DON'T YOU?!",
        "???: MURDER MURDER MURDER MURDER",
        "MURDER MURDER MURDER MURDER",
        "MURDER MURDER MURDER MURDER",
        "Jill: ...interrupt me.",
        "",
        "",
        "Jill: (Well, this is going nowhere, let's",
        "see if I can get a drink to calm her",
        "down... or throw at her face.)",

        "",
        "",
        "",
        "Think carefully, Jill. Give her something",
        "that will calm her down.",
        "",

        "???: W-What is that?",
        "",
        "",
        "Jill: A drink. Yo're in a bar. Bars serve",
        "drinks.",
        "",
        "???: A... Bar?",
        "",
        "",
        "Jill: So I figured I should give you",
        "something to help you calm down. Don't",
        "worry, it's on the house.",
        "???: To 'calm down'? What did you spice it",
        "up with? Roofies? TTX? Pumpkins?",
        "",
        "Jill: G-God no... I wouldn't even think",
        "of it.",
        "",
        "???: Your stuttering makes you suspicious,",
        "you know?",
        "",
        "Jill: If I ever added anything like that to",
        "your drink, they'd dock my pay and tips.",
        "",
        "Jill: Not to mention I'd have to pay any",
        "lawsuits myself.",
        "",
        "Jill: And that's the best case scenario.",
        "I could get fired and lose benifits or",
        "go to jail.",
        "Jill: And trust me, the BTC LOVES to",
        "catch anyone who commits that",
        "particular felony.",
        "Jill: They'd show themselves all proud",
        "for a hefty PR boost.",
        "",
        "Jill: And the thought of going through",
        "all that is just...",
        "",
        "Jill: *BRRRRRRRRRRR*",
        "",
        "",
        "???: Even if you say that...",
        "",
        "",
        "Jill: Let's do something.",
        "",
        "",
        "Jill: If you go outside, and head just",
        "three businesses to the left, you'll find",
        "a convenience store.",
        "Jill: They sell drug tests for drinks. Tell",
        "the cashier that Dana Zane sent you.",
        "",
        "???: Hmph...",
        "",
        "",
        "Gillian: Two flying cars crashed and went",
        "boom. That's why it was so noisy.",
        "",
        "Jill: Any damage?",
        "",
        "",
        "Gillian: A hole in the street, dunno",
        "about the drivers or anything.",
        "",
        "Jill: I see.",
        "",
        "",
        "Gillian: Either way, I think I'm done",
        "here.",
        "",
        "Jill: Did you check inside the toilet",
        "paper's locker?",
        "",
        "Gillian: What about i-... OH MY GOD!",
        "",
        "",
        "Gillian: How?1 Why?! W-How?!",
        "",
        "",
        "???: I'm back. He tried to give me",
        "bandages at first though.",
        "",
        "Jill: Did you have to pay?",
        "",
        "",
        "???: No...",
        "",
        "",
        "Jill: No problem then. Try it on the",
        "drink.",
        "",
        "???: ...",
        "",
        "",
        "???: Says negative.",
        "",
        "",
        "Jill: There you go.",
        "",
        "",
        "???: But you could be in cahoots with the",
        "clerk in the store. He even knew your name!",
        "",
        "Jill: Good point, but first of all: It's not",
        "my name. I's my boss'.",
        "",
        "Jill: Second, we are pretty much part of a",
        "chain. Sorta like the Spicy Chicken of",
        "bars.",
        "Jill: And finally, I'm not making you drink",
        "this. I offered it to you as a sign of",
        "peace.",
        "Jill: I mean you ARE right. It IS",
        "suspicious on my part. Sorry.",
        "",
        "Jill: You can just ignore the drink, go",
        "through that door, and forget this ever",
        "happened.",
        "Jill: That would be it. You're at peace",
        "and nothing of value would be lost.",
        "",
        "???: ...",
        "",
        "",
        "???: Are you implying something won't",
        "have value because I ignored it?",
        "",
        "???: Are you saying my presence is so",
        "unimportant that my lack of action will",
        "yield no difference?!",
        "Jill: E-Eh?",
        "",
        "",
        "???: And what about the drink? Are you",
        "gonna let this fruit of your work go",
        "to waste so easily?!",
        "Jill: No, I...",
        "",
        "",
        "???: Well, I'll let you know I'm not that",
        "unimportant and that your work does",
        "matter!",
        "Jill: Um... not sure you should drink it",
        "all so fast.",
        "",
        "???: ...",
        "",
        "",
        "Jill: So, how was it?",
        "",
        "",

        "???: Hm...",
        "",
        "",
        "???: It was fine, but not something I'd",
        "order normally.",
        "",

        "???: *cough* Too strong... did you think",
        "this would calm me down?",
        "",
        "Jill: Um...",
        "",
        "",

        "???: It was good, I guess...",
        "",
        "",
        "???: It'll help me calm down a bit,",
        "I think.",
        "",

        "???: ...",
        "",
        "",
        "Jill: Are you alright?",
        "",
        "",
        "???: ...yrah. I guess you were telling",
        "the truth. Sorry about that.",
        "",
        "Jill: No problem. If I were you, I'd have",
        "probably reacted the same way.",
        "",
        "Jill: I should apologize for my last",
        "comment too, it came out as insensitive.",
        "",
        "???: I guess I'll stay for a while;",
        "I need to get my thoughts in order.",
        "",
        "???: Can you tell me how I got here?",
        "",
        "",
        "Jill: My boss found you unconscious",
        "and brought you here for safekeeping.",
        "",
        "Jill: Aaaand you were asleep until that",
        "car crash outside.",
        "",
        "???: I-I see...",
        "",
        "",
        "???: I guess it's better to wake up here",
        "than on the streets, stripped of clothes,",
        "dignity, and/or organs.",
        "???: ...",
        "",
        "",
        "Jill: How did you fall unconscious?",
        "Were you tired? Sick?",
        "",
        "???: I guess I'm sick... but I'd rather",
        "not talk about it.",
        "",
        "Jill: Of course.",
        "",
        "",
        "Jill: ...I'll tell you what. Your drinks",
        "are on the house tonight.",
        "",
        "???: Why would you do that?",
        "",
        "",
        "Jill: Consider it an apology on behalf",
        "of everyone here for all the trouble",
        "we've caused you.",
        "Jill: Also, something tells me you might",
        "need another drink right now.",
        "",
        "???: Yeah, you might be right.",
        "",
        "",
        "???: Okay then, I'll take you on your",
        "offer. I'll have a Piano Man.",
        "",
        "Jill: Will you be fine?",
        "",
        "",
        "???: Yeah, I just gulped the last one,",
        "so I wanna enjoy this one.",
        "",
        "Jill: Coming right up then.",
        "",
        "",

        "",
        "",
        "",
        "She's asking for a Piano man. You don't",
        "see women asking for Piano Man every day.",
        "",

        "Jill: Here.",
        "",
        "",
        "???: This is not a Piano Man... or even a",
        "Piano Woman. Are you giving me whatever",
        "you please because it's free?",
        "???: Well, you're being polite enough,",
        "so I'll let it pass this time.",
        "",
        "Jill: Right...",
        "",
        "",
        "Jill: (Sorry.)",
        "",
        "",

        "Jill: Here.",
        "",
        "",
        "???: Misgendered that Pianist, though...",
        "",
        "",
        "???: Don't tell me you're like my mom",
        "with her politics about what's 'for boys'",
        "and what's 'for girls'.",
        "???: That line of thinking led to her",
        "buying me an erotic cast-off figure",
        "when I was, like, five.",
        "Jill: Erotic cast-off figure?",
        "",
        "",
        "???: Basically, a REALLY detailed sort-of",
        "PVC statue with clothes you can take off.",
        "",
        "???: She bought it thinking 'Hey, it's",
        "just another doll.'",
        "",
        "???: ...and then justified it by saying",
        "something like 'Well, you'll have to",
        "learn about your body sooner or later.'",
        "???: ...I still wish I had",
        "GLO-RI-A-sama's body.",
        "",
        "Jill: I-I see...",
        "",
        "",
        "Jill: (Who? And what the hell is a",
        "'sama'?)",
        "",

        "Jill: Here.",
        "",
        "",
        "???: Yeah. This is the one.",
        "",
        "",
        "???: My dad used to drink these before",
        "an actual pianist attempted to kill",
        "him.",
        "Jill: What did he do? Your dad, I mean.",
        "To provoke the pianist like that.",
        "",
        "???: Wrong place at the wrong time,",
        "I guess.",
        "",
        "???: He was relaxing in a bar when",
        "suddenly the pianist leapt off the stage",
        "and started punching him.",
        "???: Some say he was off his meds and",
        "that my dad looked like some music critic",
        "that had bashed him.",
        "???: I still hold my stance that he just",
        "got too excited. Jazz does that to you.",
        "",
        "Jill: I see...",
        "",
        "",
        "Jill: The Piano Man has an interesting",
        "story.",
        "",
        "Jill: It was originally created by a",
        "bartender in honor of a pianist friend",
        "of his that had just died.",
        "Jill: Apparently, it mixes all the flavors",
        "said friend liked the most.",
        "",
        "???: Oh, that's nice.",
        "",
        "",

        "???: So this is how it feels to go for a",
        "drink at the end of a long hard day at",
        "work.",
        "???: I'm not sure if I like the fact that",
        "I'm falling into that.",
        "",
        "Jill: Where do you work? Miss...",
        "",
        "",
        "Kim: Call me Kim.",
        "",
        "",
        "Kim: I don't know if I can say I 'work'",
        "yet, though. I'm still just an intern.",
        "",
        "Jill: Can I ask where?",
        "",
        "",
        "Kim: Have you ever heard of a newspaper",
        "called 'The Augmented Eye'?",
        "",
        "Jill: I read it every morning. In fact,",
        "Donovan D. Dawson was here earlier.",
        "",
        "Kim: ...I knew I smelled his nasty",
        "cologne.",
        "",
        "Kim: That bastard leaves his reek",
        "wherever he goes.",
        "",
        "Jill: So, you believe me?",
        "",
        "",
        "Kim: I do.",
        "",
        "",
        "Kim: God, you have no idea how much I",
        "hate that chauvinistic horseblower.",
        "",
        "Jill: *pffft* *ahem*",
        "",
        "",
        "Jill: Harsh words...",
        "",
        "",
        "Kim: The worst part is that I kind of",
        "admire the way he does stuff.",
        "",
        "Kim: He's so forceful about the things",
        "he wants that people have it done before",
        "they realize what's going on.",
        "Kim: He even got a pizza delivery boy",
        "to work server maintenance.",
        "",
        "Kim: A full week passed before the pizza",
        "shop asked where the hell he was.",
        "",
        "Kim: And would you believe it? The guy",
        "became decent at server maintenance,",
        "despite having no previous experience.",
        "Kim: It's kinda admirable, but at the same",
        "time I hate his guts! UGH!",
        "",
        "Kim: Knowing that I have to work for him,",
        "it's... AGH!",
        "",
        "Jill: Why are you working there, then?",
        "",
        "",
        "Kim: ...",
        "",
        "",
        "Jill: Did I ask something I shouldn't have?",
        "",
        "",
        "Kim: N-No... don't fret about it. I'd",
        "rather not talk about it, though.",
        "",
        "Jill: Fair enough.",
        "",
        "",
        "Kim: What's your name, bartender?",
        "",
        "",
        "Jill: Call me Jill.",
        "",
        "",
        "Kim: Is it hard to be a bartender, Jill?",
        "",
        "",
        "Jill: I guess it's as hard as being",
        "a cook somewhere.",
        "",
        "Jill: You keep going through the motions",
        "while trying to provide something",
        "of quality.",
        "Jill: All while answering the whimsy of",
        "people's orders.",
        "",
        "Jill: I think the hardest part is dealing",
        "with the chemical hazards some people",
        "might leave behind. Why?",
        "Kim: At one point I thiught about being",
        "a bartender...",
        "",
        "Kim: ...but I was afraid they'd make me",
        "wear skimpy clothes and dance or",
        "something.",
        "Jill: (Here we go again...)",
        "",
        "",
        "Jill: Well, it depends on where you",
        "start working, you know?",
        "",
        "Jill: I guess I was lucky Valhalla didn't",
        "end up being a tacky disco overseen by a",
        "DJ with an afro.",
        "Jill: My boss just wanted a comfy place,",
        "I think.",
        "",
        "Kim: Your boss sounds like an interesting",
        "person. What with wanting to put me",
        "somewhere safe and all that.",
        "Jill: She is! She's so cool and collected,",
        "but has no qualms about showing excitement",
        "about stuff.",
        "Jill: Sure, she's been a bit tense the",
        "last couple of days...",
        "",
        "Jill: But even when you're with her",
        "avarything just feels under control.",
        "",
        "Jill: She also has this mechanical arm.",
        "I have no idea how she got it, but...",
        "",
        "Kim: ...heh.",
        "",
        "",
        "Jill: ...",
        "",
        "",
        "Jill: ...sorry, I got carried away.",
        "",
        "",
        "Kim: It was fun to see you break the",
        "'wise bartender' character you're",
        "using here.",
        "Jill: (I do that?)",
        "",
        "",
        "Kim: It'd be nice to meet this boss",
        "of yours sometime and thank her.",
        "",
        "Jill: Shall I call her? She'd be glad",
        "to know you're okay.",
        "",
        "Kim: Oh no, I shouldn't pester her",
        "that way.",
        "",
        "Kim: And besides, it's getting late and",
        "I don't want to abuse your generosity.",
        "",
        "Jill: You can ask for another one,",
        "although I don't know how much alcohol",
        "you can handle.",
        "Kim: I think I can handle another drink.",
        "One Branditini, please.",
        "",
        "Jill: Coming right up.",
        "",
        "",

        "",
        "",
        "",
        "She wants a Brand-... sorry, a Mar-...",
        "AGH! A BRANDITINI! Yeah, that.",
        "",

        "Jill: Here you go.",
        "",
        "",
        "Kim: I don't think I can complain about",
        "this, what with the drink being free",
        "and all, but...",
        "Kim: This isn't my order.",
        "",
        "",
        "Kim: Oh well... cheers!",
        "",
        "",

        "Jill: Here.",
        "",
        "",
        "Kim: Yup, this seems like the stuff.",
        "",
        "",
        "Kim: Cheers!",
        "",
        "",

        "Kim: *ahem* *cough* *ahem*",
        "",
        "",
        "Jill: Um... are you alright?",
        "",
        "",
        "Kim: Yeah, just a bit... *ahem* dizzy.",
        "",
        "",
        "Jill: And you're clearing your throat?",
        "",
        "",
        "Kim: It... *cough* helps me focus a bit.",
        "",
        "",
        "Kim: ...yeah. I'm better now.",
        "",
        "",
        "Kim: Hey Jill, do you work with other",
        "women?",
        "",
        "Jill: I work FOR a woman, but my only",
        "co-worker is male, why?",
        "",
        "Kim: You LUCKY bitch. Err... I mean...",
        "y-you have no idea the heaven you",
        "live in.",
        "Kim: When I started my internship,",
        "every intern was female.",
        "",
        "Kim: Have you ever tried competing with",
        "women for a good spot? They are relentless.",
        "",
        "Jill: Have you tried making friends with",
        "any of them?",
        "",
        "Kim: FRIENDS?! Those cunts aren't in it",
        "for friendship, they're out for BLOOD!",
        "",
        "Kim: Err... s-sorry, I mean...",
        "",
        "",
        "Kim: The other day I got an assignment,",
        "and all I got for my efforts was an",
        "afternoon spent locked in the bathroom.",
        "Kim: And this other time? When our",
        "supervisor praised me? I'm still looking",
        "for my briefcase.",
        "Kim: UGH! Sometimes I just want to take",
        "all those bitches and throw them in the",
        "sewers or something.",
        "Kim: Let the lizardmen feast on their",
        "livers.",
        "",
        "Kim: I'm just so tired of having to",
        "deal with that.",
        "",
        "Kim: Tired of having to put up with",
        "them...",
        "",
        "Kim: Tired... tired...",
        "",
        "",
        "Kim: Mmm...",
        "",
        "",
        "Jill: No sleeping here, please. Do you",
        "want me to call you a cab?",
        "",
        "Kim: Would you be so kind?",
        "",
        "",
        "Jill: ...",
        "",
        "",
        "Jill: Hey, it's Jill, can you send",
        "us a cab?",
        "",
        "Jill: The client? Just a second.",
        "",
        "",
        "Jill: Hey Kim, I'm gonna need your",
        "full name.",
        "",
        "Kim: Kimberly... La Vallette...",
        "",
        "",
        "Jill: Wow, what a flowery name.",
        "",
        "",
        "Jill: Kimberly La Vallette... no, I have",
        "no idea how to spell it... no, she's too",
        "sleepy to answer that.",
        "Jill: Ok... fine. Thanks a lot.",
        "",
        "",
        "Jill: They'll be here in...",
        "",
        "",
        "Kim: ...zzzzzzzzzzzzzzzzzz.",
        "",
        "",
        "Jill: ...a minute.",
        "",
        "",
        "Jill: (She's been through a lot today,",
        "I guess.)",
        "",
        "Gillian: Hey Jill, bathroom's done.",
        "I'm leaving.",
        "",
        "Jill: Guide Miss La Vallette to her",
        "cab on your way out, please.",
        "",
        "Gillian: Oh, she woke up?",
        "",
        "",
        "Jill: And fell asleep again.",
        "",
        "",
        "Gillian: Sure, anything for a client.",
        "",
        "",
        "Gillian: Excuse me Miss, please help",
        "me walk you to your cab.",
        "",
        "Kim: *mumble* Pickpockets... *mumble*",
        "",
        "",

        "Kim: Hey Jill, was this job, like, a",
        "lifelong dream or something?",
        "",
        "Jill: Not really. It just kinda happened.",
        "",
        "",
        "Jill: One thing led to another and BAM,",
        "bartending.",
        "",
        "Kim: Do you regret not fulfilling a",
        "dream?",
        "",
        "Jill: The only dream I can remember",
        "being passionate about was buying a",
        "Model Warrior Julianne arcade machine.",
        "Jill: Can't say I've given up on that",
        "one yet. But alas, adult stuff needs",
        "to be paid for first.",
        "Kim: You've never had a dream you",
        "wanted to chase?",
        "",
        "Jill: Not really. I mean, most of my",
        "dreams have been silly things or",
        "childish dreams.",
        "Kim: Childish dreams?",
        "",
        "",
        "Jill: Having a room where every piece of",
        "furniture talks, being a Model Warrior...",
        "",
        "Kim: OH! Childish dreams, yeah.",
        "",
        "",
        "Jill: ...",
        "",
        "",
        "Kim: I remember I wanted to live in a Koi",
        "pond when I was seven. The fish seemed to",
        "be having a blast to me.",
        "Kim: So, no dreams?",
        "",
        "",
        "Jill: None that I felt particularly",
        "motivated to chase, no.",
        "",
        "Jill: I mean, I'm fascinaed by AIs, but",
        "I just couldn't find it in me to study",
        "that.",
        "Jill: So, I picked something I found nice",
        "and moved on.",
        "",
        "Jill: And somewhere along the way, I",
        "became a bartender.",
        "",
        "Kim: I see...",
        "",
        "",
        "Gillian: FINALLY.",
        "",
        "",
        "Gillian: Those dogs left a mess I'm not",
        "gonna forget any time soon.",
        "",
        "Gillian: I mean, how the hell did they",
        "throw toilet paper out the window?!",
        "",
        "Gillian: ...oh, a client. Good night",
        "ma'am.",
        "",
        "Gillian: Jill, I'm gonna leave early.",
        "I need to take care of the smell",
        "clinging to my body.",
        "Jill: Sure.",
        "",
        "",
        "Kim: Um... who was he?",
        "",
        "",
        "Jill: A ghost. Nobody you should worry",
        "about.",
        "",
        "Kim: Oh...",
        "",
        "",
        "Gillian: I HEARD THAT!",
        "",
        "",
        "Jill: Why were you asking all those",
        "questions?",
        "",
        "Kim: Because now that I think about it,",
        "I don't really have a dream job or",
        "anything like that.",
        "Jill: I think we idealize the idea of a",
        "dream job too much.",
        "",
        "Jill: Not everyone walks around with a",
        "clear idea of what they want in life.",
        "",
        "Jill: Some take a liking to a job,",
        "others find it after many failed",
        "attempts.",
        "Jill: Sometimes life takes an unexpected",
        "turn that makes you change your plans...",
        "",
        "Jill: ...",
        "",
        "",
        "Jill: ...what I mean is: Don't worry",
        "too much about it.",
        "",
        "Kim: Maybe you're right.",
        "",
        "",
        "Kim: Well, I'm gonna take my leave now.",
        "Thank you for everything.",
        "",
        "Kim: Please thank your boss on my behalf.",
        "Bye.",
        "",
        "Jill: Thank you and come again.",
        "",
        "",

        "Jill: And that's it.",
        "",
        "",
        "Dana: Are we done for the night?",
        "",
        "",
        "Jill: Seems like it.",
        "",
        "",
        "Dana: Where's Gil? And... where's the",
        "girl that was here?",
        "",
        "Jill: Gil cleaned the bathroom and",
        "left because he stank.",
        "",
        "Jill: Kim woke up, had a couple of drinks,",
        "and left.",
        "",
        "Dana: So she's called Kim.",
        "",
        "",
        "Dana: How did she look to you? How was",
        "she?",
        "",
        "Jill: She was freaked out when she woke",
        "up, but she managed to calm down.",
        "",
        "Dana: ...",
        "",
        "",
        "Jill: Are you worried about her?",
        "",
        "",
        "Dana: Wouldn't you be?",
        "",
        "",
        "Jill: I don't know.",
        "",
        "",
        "Jill: Hey Boss, do you feel like",
        "calling you 'Boss' is too",
        "impersonal?",
        "Dana: Hm? Not really, no.",
        "",
        "",
        "Dana: It's not like you call me that",
        "because I'm a stranger. Just out of",
        "habit.",
        "Jill: Oh...",
        "",
        "",
        "Dana: Anyway, you're free to go after",
        "you finish washing up the glasses.",
        "",
        "Dana: Let me transfer you today's payment.",
        "Maybe I'll give Gil a small bonus for",
        "dealing with the bathroom.",




        "And with that, this demo is over.",
        "It took me two months to get this much",
        "working which is surprisingly short.",
        "Anyway, I'm not sure if I'll go on",
        "with this project. But please do tell me",
        "if you liked it.",
        "",
        "",
        "",
        "RESTART THE GAME",
        "",
        "",

    };


    constexpr const char* drink_names[] = // an array for storing drink names for the lower part of the mixing screen
    {
        "#&%@*$%",
        "Bad Touch",
        "Beer",
        "Bl Jane",
        "Bl Light",
        "Bl Fairy",
        "Br-tini",
        "C Velvet",
        "Cr Spike",
        "Fl Dream",
        "Fr Weaver",
        "Fr Water",
        "Gr Temple",
        "Gut Punch",
        "Marsblast",
        "Mer Blast",
        "Moonblast",
        "Piano Man",
        "Piano Woman",
        "Piledriver",
        "Sp Star",
        "Sugar Rush",
        "Sun Cloud",
        "Suplex",
        "Zen Star",
        "Fl Moai",
        "Bad Touch",
        "Beer",
        "Bl Jane",
        "Bl Light",
        "Bl Fairy",
        "Br-tini",
        "C Velvet",
        "Cr Spike",
        "Fl Dream",
        "Fr Weaver",
        "Fr Water",
        "Gr Temple",
        "Gut Punch",
        "Mer Blast",
        "Moonblast",
        "Piledriver",
        "Sp Star",
        "Sugar Rush",
        "Sun Cloud",
        "Suplex",
        "bar 1",
        "bar 2",
        "bar 3",
        "bar 4",
    };

    constexpr int situations[] = // 0 - empty bar, 1 - anna TV, 2 - normal anna silent, 3 - smiling anna talking, 4 - glitching anna talking, 5 - glitching anna looking 
    // away and talking, 6 - normal anna looking at the player and talking, 7 - dark screen, 8 - normal jill silent, 9 - normal jill talking, 10 - glitching anna silent
    //11 - normal gil talking, 12 - normal gil silent, 13 - fucked up gil silent, 14 - gil cods talking, 15 - gil cods silent, 16 - fucked up gil talking,17 - normal gil silent anna tv, 666 - go to mixing
    //18 - surprised gil talking, 19 - surprised gil silent, 20 - gil normal silent sliding from right to center
    //31 - gil sliding to the right, dana silent and kim silent eyes closed appearing on the left
    //32 - gil on the right, dana normal talking and kim silent closed on the left, 33 - gil normal talking on the right, dana normal silent and kim silent closed on the left
    //34 - gil on the right, dana normal talking and kim silent closed on the left fading out
    //21 - fucked up gil fading out 22 - angry gil fading out
    //48 - donovan normal talking, 49 - donovan normal silent, 50 - donovan smiling silent open, 51 - donovan smiling silent closed, 52 - donovan smiling talking open, 53 - donovan smiling talking closed
    //54 - donovan normal fading out
    //64 - ingram talking, 65 - ingram silent, 66 - ingram silent dana talking, 67 - ingram dana silent, 68 - ingram silent dana fading out,69 - ingram fading out (noice)
    {
        0,0,1,3,10,4,4,5,3,6,4,3,7,7,7, // Prologue
        0,11,12,12,13,13,14,15,11,12,11,16,13,16,13,11,12,12,17,12,12,12,12,12,11,12,16,13,11,12,11,12,11,11,11,11,11,12,11,11,11,11,11,12,14,15,666,666, // this 666 at the end is the memory thingy
        15,16,16,15,11,12,16,11,11,11,11,14,11,11,12,11,14,15,666,666, // day 1 tutorial
        15,13,13,16,13, 15,11,11,12, 15,18,11, 18,19,11,11,11,11,11,16,13,11, // day 1 tutorial end
        12,31,31,32,33,32,31,34,20,12,12,11,12,12,11,12,11,12,16,13,13,11,12,11,12,12,11,11,12,16,13,21, // day 1 danakim and gil sent to clean the bathroom
        0,0,0, 0,0, // jukebox placeholder
        0,48,49,666,666,49,49,48,48,48,49,666,666,49,48,48,48,49, 49,48,49, 49,53,49,  49,49,48,48,49,48, 49,48,49,666,666,666,49,48,48,48,49, 49,49,48, 49,0,48, 49,53,49, 49,53,50,  // day 1 first order by donovan (fucking hate it)
        48,48,49,49,52,52,50,50,48,48,48,53,53,51,51,51,48,48,48,48,48,49,49,48,48,49,48,48,48,48,48,52,52,50,50,48,48,48,49,49,53,48,49,48,48,48,48,49,48,48,48,49,48,49,48,48,49, // donovan chitchat 753
        666,666,49,49,48,48,49, 49,48,48,48,49, 49,48,48,49, 49,53,51,48,49, // day 1 second orer of Donovan
        48,49,48,49,48,49,49,48,48,49,48,49,48,48,48,48,48,49,48,52,52,50,48,48,49,49,49,53,53,51,51,51,51,51,48,48,48,49,49,49,49,48,48,49,49,49,52,50,48,48,49,49,48,49,49,49,48,49,48,49,49,49,49,49,48,49,49,49,48,48,49,48,53,51,53,53,51,53,53,51,48,48,48,48,49,48,48,49, // Donovan chitchat 2: electric boogaloo
        666,666, 49,49,48,49, 49,48,48,49, 49,48,49, 49,53,51, // day 1 third order of Donovan
        49,48,48,49,48,48,48,48,48,49,49,48,48,49,54, // donovan bad last drink
        48,49,49,49,49,49,52,52,48,49,48,48,48,49,48,48,48,48,48,48,48,54,0,0,0, // donovan good last drink (or just drunk)
        48,48,49, 666,666, 49,49,48,49, 49,48,48, 49,48,49, 49,48,48,49, // donovan third drink bitter thing

        0,0,11,11,12,11,12,22,0, // gil is angry abt the toilets
        0,0,64,65, 666,666, 65,64,64,64,65, 65,64,65,64,65,65,64, 65,64,65, // ingram the first order
        64,65,64,65, 64,65,65,65, 64, 65,64,65,65,64,65,64,65,65,64,64,65,64,65,64,66,67,66,68,65,64,65,64,65,64,64,64,65,65,65,64,65,65,64,64,65,65,65,64,65,65,65,65,65, // ingram chitchat 1
        65,64,65,65, 666,666, 64,65,64, 64,65,64,64,65,64,64,65,64, 64,65,64,65,64, 65,64, 65,65, // ingram drink 2
        64,65,65,64,65,64,64,64,64,64,65,65,64,65,65,65,64,65, // FAKE ORGASMS
        64,65,64,65, 666,666, 64,65,65, 65,64, 64,65, // ingram order 3
        64,65,64,65,64,64,65,65,64,65,64,65,64,64,64,64,64,65,65,64,65,64,65,64,64,65,64,65,69,0, // empty
        64,65,65,64,65,65,64,64,64,65,64,64,64,65,64,65,65,65,64,65,64,64,64,64,65,64,64,64,64,65,65,64,64,64,64,64,64,64,65,65,64,64,65,64,65,64,64,64,65,69,0, // white knights
        0,0,0,667 // day 1 break
    };

    constexpr int situations_2[] = // 75 - sei helmet fade in, 76 - sei helmet, 77 - sei helmet taking off anf fade out, 78 - sei normal fade in,
    // 79 - sei normal silent, 80 - sei normal talking, 81 - sei worried silent, 82 - sei worried talking,
    // 83 - sei smiling silent, 84 - sei smiling talking, 85 - sei normal fading out,
    // 101 - barground shake, 86 - sei drunk talking, 87 - sei drunk silent, 88 - sei drunk fading out, 89 - sei fading in and out
    // 90 - sei smiling talking shake, 91 - sei worried fading out,
    // 102 - kim fade in, 103 - kim normal silent, 104 - kim normal talking, 105 - kim angry silent, 106 - kim angry talking,
    // 107 - kim MURDER (12"), 108 - kim to the left, 11 - normal gil silent, 12 - normal gil talking,
    // 18 - surprised gil talking, 19 - surprised gil silent, 23 - normal gil fading out,
    // 109 - kim sliding from left to center, 110 - kim sad talking, 111 - kim sad silent, 112 - kim sleep silent, 113 - kim sleep talking,
    // 114 - sleepy kim fading out, 24 - fucked up gil fading in, 120 - fucked up gil fading in kim silent, 121 - fucked up gil talking kim silent, 122 - normal gil talking kim silent,123 - fucked up gil fading out kim silent
    // 115 - normal kim fading out, 140 - dana fade in, 141 - dana normal silent, 142 - dana normal talking,
    // 143 - dana serious talking, 144 - dana serious silent,
    {
        0,0,0,// day 1 break end, jukebox
        0,75,76,76,76,76,77,78,79,79,80,82,81,80,80,80,82,81,80,79, // Sei taking off helmet and making an order
        666,666, 79,82,81, 79,82,82,80, 79,82,82, 79,80, // Sei first order
        79,79,80,79,80,80,79,84,84,84,83,80,80,79,80,79,80,80,79,80,80,79,84,84,84,84,83,82,81,80,80,80,79,80,79,79,80,79,80,82,81, // sei's sights and sighs
        666,666, 81,80,80,79,80,80,79, 81,80,79,80,80,79,80, // sei second order
        80,79,80,79,80,80,79,80,79,81,81,81,82,82,81,82,81,82,80,79,79,84,83,84,84,83,80,80,80,80,80,80,79,80,80,82,81,81,80,80,80,79,80,80,80,79,80,80,80,79,80,80,80,79,79,80,79, // sei dialogue 2
        80,79,80,79,85,0,0,101,0,0, // sei drunk early
        84,84,83,84,83, // sei not drunk early
        666,666, 79,82,82, 79,80,80, // sei third order
        86,87,86,86,86,86,86,86,87,87,88,0,101,89,0,0,0,0, // sei drunk
        84,83,84,84,84,83,84,90,82,81,82,81,91,0,0,0,0, // sei sober
        0,0,102,103,103,104,104,103,103,104,103,103,103,103,106,106,106,106,105,106,106,106,107,107,107, // MURDER MURDER MURDER
        666,666, 104,103,104,103,106,105,106,105,105,105,105,105,105,105,104,103,103,103,108,11,12,11,12,11,12,23,0,109,103,104,103,103,104,103,104,103,103,103,103,103,103,103,104,104,103,104,103,104,103,103,103, // kim first order
        103,104, 111,110, 104,104,// drink reacton
        112,112,104,103,103,104,104,103,103,104,104,112,112,113,112,112,104,103,103,104,104,103,104,103, // kim chitchat 1
        666,666, 103,104,104,103,103, 103,104,104,104,103,104,104,104,104,103,103, 103,104,104,103,113,113,104,104,103,103,103,103,104, // kim second order
        104,104,103,104,104,103,104,103,104,104,103,104,104,103,103,104,104,104,104,104,104,104,103,103,103,104,103,104,103,104,103,103,103,103,104,104,103,103,103,103,104,103,103,103,103,103,103,103,104,103,104,103,104,104,103,104,103, // kim chitchat 2
        666,666, 103,104,104,104, 103,104,104, // kim third order
        103,103,104,103,104,104,104,103,106,104,106,105,106,106,106,106,106,113,113,113,113,112,112,113,112,112,112,112,113,112,112,112,112,114,0,0,24,13,11,12,11,23,0, // kim drunk
        104,103,103,104,103,103,104,103,104,103,104,103,113,104,103,103,103,103,104,103,120,121,122,123,103,104,103,103,103,103,113,112,112,112,112,112,112,104,104,115,0, // kim sober
        0,140,142,143,144,144,143,143,144,144,144,143,144,144,142,142,141,142,142, // day 1 end
        0,0,0,0 // day 1 end message (TBD)
    };

    constexpr int total_lines = sizeof(lines);
    constexpr int total_lines_2 = sizeof(lines_2);

    constexpr int total_situations = sizeof(situations);
    constexpr int total_situations_2 = sizeof(situations_2);

    constexpr int total_drink_names = sizeof(drink_names);
}

namespace game_vars // ice, age, adelhyde, flanergide, bronson, delta, karmotrine, blend
{
    constexpr int bad_touch[] =      {1,0,0,2,2,2,4,0,250}; // ice, 2 fl, 2 br, 2 d, 4 kar, mixed
    constexpr int beer[] =           {0,0,1,2,2,1,4,0,200};
    constexpr int bleeding_jane[] =  {0,0,0,3,1,3,0,1,200};
    constexpr int bloom_light[] =    {1,1,4,2,0,1,3,0,230};
    constexpr int blue_fairy[] =     {0,1,4,1,0,0,0,0,170};
    constexpr int branditini[] =     {0,1,6,0,0,3,1,0,250};
    constexpr int cobalt_velvet[] =  {1,0,2,3,0,0,5,0,280};
    constexpr int crevice_spike[] =  {0,0,0,4,0,0,0,1,140};
    constexpr int fluffy_dream[] =   {0,1,3,0,0,3,0,0,170};
    constexpr int fringe_weaver[] =  {0,1,1,0,0,0,9,0,260};
    constexpr int frothy_water[] =   {0,1,1,1,1,1,0,0,150};
    constexpr int grizzly_temple[] = {0,0,3,0,3,3,1,1,220};
    constexpr int gut_punch[] =      {0,1,0,1,5,0,0,0,80};
    constexpr int marsblast[] =      {0,0,0,4,6,1,2,1,170};
    constexpr int mercury_blast[] =  {1,0,1,3,1,3,2,1,250};
    constexpr int moonblast[] =      {1,0,6,1,0,1,2,1,180};
    constexpr int piano_man[] =      {1,0,2,5,3,5,3,0,320};
    constexpr int piano_woman[] =    {0,1,5,3,5,2,3,0,320};
    constexpr int piledriver[] =     {0,0,0,3,3,0,4,0,160};
    constexpr int sparkle_star[] =   {0,1,2,0,0,1,0,0,150};
    constexpr int sugar_rush[] =     {0,0,2,0,0,1,0,0,150};
    constexpr int sunshine_cloud[] = {1,0,2,0,2,0,0,1,150};
    constexpr int suplex[] =         {1,0,0,3,4,0,3,0,160};
    constexpr int zen_star[] =       {1,0,4,4,4,4,4,0,210};
    constexpr int flaming_moai[] =   {0,0,1,3,1,2,5,0,150};
    constexpr int bad_touch_b[] =      {1,0,0,4,4,4,8,0,500}; // ice, 4 fl, 4 br, 4 d, 8 kar, mixed
    constexpr int beer_b[] =           {0,0,2,4,4,2,8,0,400};
    constexpr int bleeding_jane_b[] =  {0,0,0,6,2,6,0,1,400};
    constexpr int bloom_light_b[] =    {1,1,8,4,0,2,6,0,460};
    constexpr int blue_fairy_b[] =     {0,1,8,2,0,0,0,0,340};
    constexpr int branditini_b[] =     {0,1,12,0,0,6,2,0,500};
    constexpr int cobalt_velvet_b[] =  {1,0,4,6,0,0,10,0,560};
    constexpr int crevice_spike_b[] =  {0,0,0,8,0,0,0,1,280};
    constexpr int fluffy_dream_b[] =   {0,1,6,0,0,6,0,0,340};
    constexpr int fringe_weaver_b[] =  {0,1,2,0,0,0,18,0,520};
    constexpr int frothy_water_b[] =   {0,1,4,2,2,2,0,0,300};
    constexpr int grizzly_temple_b[] = {0,0,6,0,6,6,2,1,440};
    constexpr int gut_punch_b[] =      {0,1,0,2,10,0,0,0,160};
    constexpr int mercury_blast_b[] =  {1,0,2,6,2,6,4,2,500};
    constexpr int moonblast_b[] =      {1,0,12,2,0,2,4,1,360};
    constexpr int piledriver_b[] =     {0,0,0,6,6,0,8,0,320};
    constexpr int sparkle_star_b[] =   {0,1,4,0,0,2,0,0,300};
    constexpr int sugar_rush_b[] =     {0,0,4,0,0,2,0,0,300};
    constexpr int sunshine_cloud_b[] = {1,0,4,0,4,0,0,1,300};
    constexpr int suplex_b[] =         {1,0,0,6,8,0,6,0,320};

}

class TextManager // turns ROM text data into string_view for the sprite_text_generator based on the index
{
    public:
        static bn::string_view get_line(int index, int day_c) 
        {
            switch (day_c)
            {
                case 0:
                    if(index >=0 && index < game_text::total_lines)
                    {
                        return bn::string_view(game_text::lines[index]);
                    }
                break;

                case 1:
                    if(index >=0 && index < game_text::total_lines)
                    {
                        return bn::string_view(game_text::lines[index]);
                    }
                break;

                case 2:
                    if(index >=0 && index < game_text::total_lines_2)
                    {
                        return bn::string_view(game_text::lines_2[index]);
                    }
                break;
            }
            
            // Unknown
        }
        static int get_length(int index_l, int day_c) 
        {
            switch(day_c)
            {
                case 0:
                    if(index_l >=0 && index_l < game_text::total_lines)
                    {
                        bn::string_view temp = bn::string_view(game_text::lines[index_l]);
                        return temp.size();
                    }
                break;

                case 1:
                    if(index_l >=0 && index_l < game_text::total_lines)
                    {
                        bn::string_view temp = bn::string_view(game_text::lines[index_l]);
                        return temp.size();
                    }
                break;

                case 2:
                    if(index_l >=0 && index_l < game_text::total_lines_2)
                    {
                        bn::string_view temp = bn::string_view(game_text::lines_2[index_l]);
                        return temp.size();
                    }
                break;

                
            }
            
           
        }
        static int get_situation(int sit, int day_c)
        {
            switch(day_c)
            {
                case 0:
                    if(sit >=0 && sit < game_text::total_situations)
                    {
                        return int(game_text::situations[sit]);
                    }
                break;

                case 1:
                    if(sit >=0 && sit < game_text::total_situations)
                    {
                        return int(game_text::situations[sit]);
                    }
                break;

                case 2:
                    if(sit >=0 && sit < game_text::total_situations_2)
                    {
                        return int(game_text::situations_2[sit]);
                    }
                break;
            }
            
        }
        static bn::string_view get_drink_name(int index) 
        {
            if(index >=0 && index < game_text::total_drink_names)
            {
                return bn::string_view(game_text::drink_names[index]);
            }
            // Unknown
        }
};



namespace{
    void prologue()
    {
        int t = 0;
        int current_index = 0; // calculated index
        int line_1_index = 0; 
        int line_2_index = 0;
        int line_3_index = 0;
        bool line_change = true; // action flag for changing the text and the situation
        int a_press_timeout = 0; // timeout for the a button

        int anna_x = 0; //  abg coordinates
        int anna_y = -8; //  abg coordinates
        int anna_anim; // counter for the talking animation
        int anna_blink_time = 180; // stores the current timer for the blinking
        int anna_blink_count = 0; // counts up till the next blink
        int anna_blinking = 0; // counts up till the end of blinking
        bool anna_blink_flag = false;
        bool anna_fade_in_flag = false;
        bn::fixed anna_fade_in_intensity = 1.0;
        int anna_glitch_timer = 0;
        bool anna_glitch_flag = false;
        int anna_tv_counter = 0;
        int anna_tv_timer = 0;
        
        bn::random random;
        int line_1_appear = 0;
        int line_2_appear = 0;
        int line_3_appear = 0;
        bool line_1_ready = false;
        bool line_2_ready = false;
        bool line_3_ready = false;
        int line_1_length = 0;
        int max = 0;
        int line_skip = 0;
        int est_time = 0;
        int sym_sum = 0;
        int blink = 0; // timer for blinking the triangle
        bool frame_skip = false; // frame skipping flag for text generation
        int sit_memory = 0;
        constexpr int tv_x = 24;
        constexpr int tv_y = -61;
        int fan_rot = 0; // rotation var for the fan
        int speech_counter = 0;

        bn::sprite_text_generator line_1(common::variable_8x8_sprite_font);
        bn::sprite_text_generator line_2(common::variable_8x8_sprite_font);
        bn::sprite_text_generator line_3(common::variable_8x8_sprite_font);
 
        line_1.set_left_alignment();
        line_2.set_left_alignment();
        line_3.set_left_alignment();
        line_1.set_bg_priority(1);
        line_2.set_bg_priority(1);
        line_3.set_bg_priority(1);


        bn::vector<bn::sprite_ptr, 64> text_sprites_1;
        bn::vector<bn::sprite_ptr, 64> text_sprites_2;
        bn::vector<bn::sprite_ptr, 64> text_sprites_3;


        bn::string_view line1 = TextManager::get_line(0,0);
        bn::string_view line2 = TextManager::get_line(1,0);
        bn::string_view line3 = TextManager::get_line(2,0);


        line_1.generate(-112, 48, line1, text_sprites_1);
        line_2.generate(-112, 60, line2, text_sprites_2);
        line_3.generate(-112, 72, line3, text_sprites_3);



        
        bn::regular_bg_ptr bg_bg = bn::regular_bg_items::bg.create_bg(0, -15);
        bn::regular_bg_ptr textbox = bn::regular_bg_items::textbox.create_bg(8, -48);
        bn::regular_bg_ptr malevich = bn::regular_bg_items::malevich.create_bg(0, 0);
        malevich.set_visible(false);
        textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0);
        bg_bg.set_priority(3);
        textbox.set_priority(3);
        bn::sprite_ptr fan = bn::sprite_items::fan.create_sprite(tv_x - 50, tv_y - 3);
        fan.set_visible(true);
        fan.set_bg_priority(0);

        bn::affine_bg_ptr anna_abg = bn::affine_bg_items::anna.create_bg(anna_x, anna_y);
        anna_abg.set_priority(1);
        anna_abg.set_wrapping_enabled(0);
        bn::sprite_ptr anna_eyes = bn::sprite_items::anna_eyes.create_sprite(anna_x - 1, anna_y - 16);
        anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);
        anna_eyes.set_bg_priority(0);
        anna_eyes.set_visible(false);
        bn::sprite_ptr anna_mouth = bn::sprite_items::anna_mouth.create_sprite(anna_x - 1, anna_y - 4);
        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
        anna_mouth.set_bg_priority(0);
        anna_mouth.set_visible(false);
        bn::bg_palette_ptr anna_palette = anna_abg.palette();
        bn::sprite_palette_ptr anna_eyes_palette = anna_eyes.palette();
        bn::sprite_palette_ptr anna_mouth_palette = anna_mouth.palette();
        //bn::bg_palette_fade_to_action anna_fade_in(anna_palette, 30, 0.0);

        bn::sprite_ptr anna_tv = bn::sprite_items::anna_tv.create_sprite(tv_x, tv_y);
        anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),0);
        anna_tv.set_bg_priority(0);
        anna_tv.set_visible(false);

        
        
        bn::music_items::dusk.play(0.3,true);

        //while(! bn::keypad::start_pressed())
         while(current_index < 45)
        {
            line_1_index = current_index;
            line_2_index = current_index + 1;
            line_3_index = current_index + 2;
            

            if (line_change == true) // generating new text
            {
                text_sprites_1.clear();
                text_sprites_2.clear();
                text_sprites_3.clear();


                bn::string_view line1 = TextManager::get_line(line_1_index,0); // looking up line data
                bn::string_view line2 = TextManager::get_line(line_2_index,0);
                bn::string_view line3 = TextManager::get_line(line_3_index,0);

                

                line_1_length = TextManager::get_length(line_1_index,0);
                //line_1_length -= 5;

                line_1.set_one_sprite_per_character(true); // first line is being drawn
                line_2.set_one_sprite_per_character(true); // the rest are not one sprite per character until it's their turn
                line_3.set_one_sprite_per_character(true);
                line_1.generate(-115, 48, line1, text_sprites_1); // generating a new line
                line_1_appear = 0;
                line_2.generate(-115, 60, line2, text_sprites_2);
                line_3.generate(-115, 72, line3, text_sprites_3);
                line_1.set_visible(false); // making all lines invisible
                line_2.set_visible(false);
                line_3.set_visible(false);


                sym_sum = TextManager::get_length(line_1_index,0) + TextManager::get_length(line_2_index,0) + TextManager::get_length(line_3_index,0);
                est_time = sym_sum/20;
                est_time--;
                if (est_time<=2)
                {
                    est_time = 2;
                }

                
                //char buffer[10];
                
                
                line_change = false;
            }


            
                switch (TextManager::get_situation(current_index/3,0)) // Making stuff happen based on the according Situations var
                {
                    case 0: // bargroud
                        anna_abg.set_visible(false);
                        anna_eyes.set_visible(false);
                        anna_mouth.set_visible(false);
                    break;
                        
                    case 1: // anna TV
                        anna_abg.set_visible(false);
                        anna_eyes.set_visible(false);
                        anna_mouth.set_visible(false);
                        anna_tv.set_visible(true);

                        if (anna_tv_counter < 4)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),0);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }

                        else if (anna_tv_counter < 7)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),1);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }

                        else if (anna_tv_counter < 12)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),2);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }

                        else if (anna_tv_counter < 15)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),3);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }

                        else if (anna_tv_counter < 17)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),4);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }

                        else if (anna_tv_counter < 20)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),5);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }
                        else
                        {
                            anna_tv_counter = 0;
                        }
                        
                        
                        if (anna_tv_timer > 360)
                        {
                            anna_tv.set_visible(false);
                        }
                        sit_memory == 1;
                    break;

                    case 2: // normal anna talking
                        if (sit_memory == 0 || sit_memory == 1)
                    {
                        anna_tv.set_visible(false);
                        anna_abg.set_visible(false);
                        anna_fade_in_flag = true;
                        anna_abg.set_x(anna_x);
                        anna_abg.set_y(anna_y);
                        anna_palette.set_fade_intensity(1.0);
                        anna_abg.set_visible(true);
                        sit_memory = 2;
                    }
                    else if (anna_fade_in_flag == true)
                    {
                        if (anna_fade_in_intensity > 0.0)
                        {
                            anna_fade_in_intensity -= 0.01;
                            if(anna_fade_in_intensity<0.0)
                            {
                                anna_fade_in_intensity = 0.0;
                            }
                            anna_palette.set_fade_intensity(anna_fade_in_intensity);
                        }
                        else
                        {
                            anna_fade_in_flag = false;
                        }
                    }
                    else
                    {
                    anna_fade_in_flag = false; // fixing a flag
                    anna_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    anna_abg.set_x(anna_x);
                    anna_abg.set_y(anna_y);
                    anna_abg.set_visible(true);
                    anna_mouth.set_visible(true);
                    anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    anna_eyes.set_visible(true);
                    anna_blink_count++;

                if (anna_blink_count >= anna_blink_time && anna_blink_flag == false) // blinking
                {
                    anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),1);
                    anna_blinking = 0;
                    anna_blink_count = 0;
                    anna_blink_flag = true;
                }
                if (anna_blink_flag == true)
                {
                    anna_blink_count++;
                    if (anna_blink_count >= 27)
                    {
                        
                        anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);
                        anna_blinking = 0;
                        anna_blink_count = 0;
                        anna_blink_time = random.get_int(180, 600);
                        anna_blink_flag = false;
                    }
                }
            }
                    break;

                    case 3: // smiling anna talking

                    //anna_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    if (sit_memory == 0 || sit_memory == 1)
                    {
                        anna_tv.set_visible(false);
                        anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 3);
                        //anna_eyes.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),3);
                        //anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),3);
                        anna_abg.set_visible(true);
                        //anna_eyes.set_visible(true);
                        //anna_mouth.set_visible(true);

                        anna_fade_in_flag = true;
                        anna_abg.set_x(anna_x);
                        anna_abg.set_y(anna_y);
                        anna_palette.set_fade_intensity(1.0);
                        //anna_eyes_palette.set_fade_intensity(1.0);
                        //anna_mouth_palette.set_fade_intensity(1.0);
                        
                        sit_memory = 2;
                    }
                    else if (anna_fade_in_flag == true)
                    {
                        if (anna_fade_in_intensity > 0.0)
                        {
                            anna_fade_in_intensity -= 0.01;
                            if(anna_fade_in_intensity<0.0)
                            {
                                anna_fade_in_intensity = 0.0;
                            }
                            anna_palette.set_fade_intensity(anna_fade_in_intensity);
                            //anna_eyes_palette.set_fade_intensity(anna_fade_in_intensity);
                            //anna_mouth_palette.set_fade_intensity(anna_fade_in_intensity);
                        }
                        else
                        {
                            anna_fade_in_flag = false;
                            //anna_abg.set_visible(true);
                        }
                    }
                    else
                {
                    anna_fade_in_flag = false; // fixing a flag
                    anna_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 0);
                    anna_abg.set_x(anna_x);
                        anna_abg.set_y(anna_y);
                        anna_abg.set_visible(true);
                        anna_mouth.set_visible(true);
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),3);
                        anna_eyes.set_visible(true);

                        if(anna_anim<=est_time)
                        {
                        if(t<9)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<36)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    }
                    else if(t<45)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<54)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<80)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else
                    {
                        t=0;
                        anna_anim++;
                    };}
                    else
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),3);
                    }
                    anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),3);
                }

                    break;

                    case 4: // glitching anna talking

                    anna_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening

                    anna_abg.set_x(anna_x);
                    anna_abg.set_y(anna_y);
                    anna_abg.set_visible(true);
                    anna_mouth.set_visible(true);
                    anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    anna_eyes.set_visible(true);

                        if(anna_anim<=est_time)
                        {
                        if(t<9)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                        anna_glitch_timer = 160;
                        anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<36)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    }
                    else if(t<45)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<54)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<80)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else
                    {
                        t=0;
                        anna_anim++;
                    };}
                    else
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                        anna_mouth.set_visible(false);
                        
                    //anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);

                    anna_blink_count++;

                    if (anna_blink_count >= anna_blink_time && anna_blink_flag == false) // blinking
                    {
                        anna_eyes.set_visible(true);
                        anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),1);
                        anna_blinking = 0;
                        anna_blink_count = 0;
                        anna_blink_flag = true;
                    }
                    if (anna_blink_flag == true)
                    {
                        anna_blink_count++;
                        if (anna_blink_count >= 27)
                        {
                            
                            anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);
                            anna_eyes.set_visible(false);
                            anna_blinking = 0;
                            anna_blink_count = 0;
                            anna_blink_time = random.get_int(180, 600);
                            anna_blink_flag = false;
                            anna_glitch_flag = true;
                            anna_glitch_timer = 0;
                        }
                    }
                    if (anna_glitch_timer<150 && anna_glitch_flag == true)
                        {
                            anna_glitch_timer++;
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 0);
                        }
                        else if (anna_glitch_timer < 156 && anna_glitch_timer >= 150 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 1);
                            anna_glitch_timer++;
                        }
                        else if (anna_glitch_timer < 160 && anna_glitch_timer >= 156 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 2);
                            anna_glitch_timer++;
                        }
                        else if (anna_glitch_timer < 164 && anna_glitch_timer >= 160 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 3);
                            anna_glitch_timer++;
                        }
                        else if (anna_glitch_timer >= 164 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 0);
                            anna_glitch_flag = false;
                            anna_eyes.set_visible(true);
                        }
                    }
                    break;

                    case 5: // glitching anna talking and looking away

                    anna_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening

                    anna_abg.set_x(anna_x);
                    anna_abg.set_y(anna_y);
                    anna_abg.set_visible(true);
                    anna_mouth.set_visible(true);
                    anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    anna_eyes.set_visible(true);

                        if(anna_anim<=est_time)
                        {
                        if(t<9)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                        anna_glitch_timer = 160;
                        anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),2);
                    }
                    else if(t<18)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<36)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    }
                    else if(t<45)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<54)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<80)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else
                    {
                        t=0;
                        anna_anim++;
                    };}
                    else
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                        anna_mouth.set_visible(false);
                        
                    //anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);

                    anna_blink_count++;

                    if (anna_blink_count >= anna_blink_time && anna_blink_flag == false) // blinking
                    {
                        anna_eyes.set_visible(true);
                        anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),1);
                        anna_blinking = 0;
                        anna_blink_count = 0;
                        anna_blink_flag = true;
                    }
                    if (anna_blink_flag == true)
                    {
                        anna_blink_count++;
                        if (anna_blink_count >= 27)
                        {
                            
                            anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),2);
                            anna_eyes.set_visible(false);
                            anna_blinking = 0;
                            anna_blink_count = 0;
                            anna_blink_time = random.get_int(180, 600);
                            anna_blink_flag = false;
                            anna_glitch_flag = true;
                            anna_glitch_timer = 0;
                        }
                    }
                    if (anna_glitch_timer<150 && anna_glitch_flag == true)
                        {
                            anna_glitch_timer++;
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 0);
                        }
                        else if (anna_glitch_timer < 156 && anna_glitch_timer >= 150 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 1);
                            anna_glitch_timer++;
                        }
                        else if (anna_glitch_timer < 160 && anna_glitch_timer >= 156 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 2);
                            anna_glitch_timer++;
                        }
                        else if (anna_glitch_timer < 164 && anna_glitch_timer >= 160 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 3);
                            anna_glitch_timer++;
                        }
                        else if (anna_glitch_timer >= 164 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 0);
                            anna_glitch_flag = false;
                            anna_eyes.set_visible(true);
                        }
                    }
                    break;

                    case 6: // normal anna talking

                    anna_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening

                    anna_abg.set_x(anna_x);
                    anna_abg.set_y(anna_y);
                    anna_abg.set_visible(true);
                    anna_mouth.set_visible(true);
                    anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    anna_eyes.set_visible(true);

                        if(anna_anim<=est_time)
                        {
                        if(t<9)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                        anna_glitch_timer = 160;
                        anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<36)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    }
                    else if(t<45)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<54)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),2);
                    }
                    else if(t<80)
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),1);
                    }
                    else
                    {
                        t=0;
                        anna_anim++;
                    };}
                    else
                    {
                        anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                        anna_mouth.set_visible(false);
                        
                    //anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);

                    anna_blink_count++;

                    if (anna_blink_count >= anna_blink_time && anna_blink_flag == false) // blinking
                    {
                        anna_eyes.set_visible(true);
                        anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),1);
                        anna_blinking = 0;
                        anna_blink_count = 0;
                        anna_blink_flag = true;
                    }
                    if (anna_blink_flag == true)
                    {
                        anna_blink_count++;
                        if (anna_blink_count >= 27)
                        {
                            
                            anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);
                            anna_eyes.set_visible(false);
                            anna_blinking = 0;
                            anna_blink_count = 0;
                            anna_blink_time = random.get_int(180, 600);
                            anna_blink_flag = false;
                            //anna_glitch_flag = true;
                            //anna_glitch_timer = 0;
                        }
                    }
                }
                    break;

                    case 7:
                        anna_abg.set_visible(false);
                        anna_eyes.set_visible(false);
                        anna_mouth.set_visible(false);
                        bg_bg.set_visible(false);
                        malevich.set_visible(true);
                    break;


                    case 10: // glitching anna silent

                    anna_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening

                    anna_abg.set_x(anna_x);
                    anna_abg.set_y(anna_y);
                    anna_abg.set_visible(true);
                    anna_mouth.set_visible(true);
                    anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                    anna_eyes.set_visible(true);

                        
                        // anna_mouth.set_tiles(bn::sprite_items::anna_mouth.tiles_item(),0);
                         anna_mouth.set_visible(false);
                        
                    //anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);

                    anna_blink_count++;


                    if (anna_blink_count >= anna_blink_time && anna_blink_flag == false) // blinking
                    {
                        anna_eyes.set_visible(true);
                        anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),1);
                        anna_blinking = 0;
                        anna_blink_count = 0;
                        anna_blink_flag = true;
                    }
                    if (anna_blink_flag == true)
                    {
                        anna_blink_count++;
                        if (anna_blink_count >= 27)
                        {
                            
                            anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);
                            anna_eyes.set_visible(false);
                            anna_blinking = 0;
                            anna_blink_count = 0;
                            anna_blink_time = random.get_int(180, 600);
                            anna_blink_flag = false;
                            anna_glitch_flag = true;
                            anna_glitch_timer = 0;
                        }
                    }
                    else // fixing eyes still closed after a smiley face
                    {
                        anna_eyes.set_tiles(bn::sprite_items::anna_eyes.tiles_item(),0);
                    }
                    if (anna_glitch_timer<150 && anna_glitch_flag == true)
                        {
                            anna_glitch_timer++;
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 0);
                        }
                        else if (anna_glitch_timer < 156 && anna_glitch_timer >= 150 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 1);
                            anna_glitch_timer++;
                        }
                        else if (anna_glitch_timer < 160 && anna_glitch_timer >= 156 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 2);
                            anna_glitch_timer++;
                        }
                        else if (anna_glitch_timer < 164 && anna_glitch_timer >= 160 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 3);
                            anna_glitch_timer++;
                        }
                        else if (anna_glitch_timer >= 164 && anna_glitch_flag == true)
                        {
                            anna_abg.set_map(bn::affine_bg_items::anna.map_item(), 0);
                            anna_glitch_flag = false;
                            anna_eyes.set_visible(true);
                        }
                    
                    break;
            
                }
            
                

                t++;

                fan_rot += 3;
                if (fan_rot >= 360)
                {
                    fan_rot = 0;
                }
                bn::fixed fan_angle (fan_rot);
                fan.set_rotation_angle(fan_angle);

                if (line_skip > 2 || frame_skip == true) // skipping some frames between drawing lines
                {
                    
                    if (line_1_ready == false && line_2_ready == false && line_3_ready == false) // setting the next character visible
                    { 
                        max = text_sprites_1.size(); // for this function the value from the vector itself is important. For other applications use TextManager::get_length
                        if (max>0) // checking if the line is empty and should be skipped
                        {
                            if (max > line_1_appear && line_1_ready == false) // setting the next character visible
                            {
                                text_sprites_1[line_1_appear].set_visible(true);
                                if (speech_counter > 0 && frame_skip == false)
                                {
                                    bn::sound_items::speech.play(1.0);
                                    speech_counter = 0;
                                }
                                else
                                {
                                    speech_counter++;
                                }
                                line_1_appear++;
                            }
                            else if (max <= line_1_appear) // checking if this is the last character
                            {
                                line_1_appear--; // IT'S IMPORTANT TO NOT OVERFILL THIS VAR. WHATEVER YOU DO, DO NOT LET IT REACH MAX VALUE!
                                if (line_1_appear < 0 && frame_skip == false)
                                {
                                    line_1_appear = 0;
                                }
                                line_1_ready = true;
                                text_sprites_1[line_1_appear].set_visible(true);
                                line_1.set_one_sprite_per_character(false);
                                line_2.set_one_sprite_per_character(true);
                                line_2_appear = 0;
                            }
                        }
                    }
                    if (line_2_ready == false && line_1_ready == true && line_3_ready == false) // setting the next character visible
                    { 
                        max = text_sprites_2.size(); // for this function the value from the vector itself is important. For other applications use TextManager::get_length
                        if (max > 0) // checking if the line is empty and should be skipped
                        {
                            if (max > line_2_appear && line_2_ready == false) // setting the next character visible
                            {
                                text_sprites_2[line_2_appear].set_visible(true);
                                if (speech_counter > 0 && frame_skip == false)
                                {
                                    bn::sound_items::speech.play(1.0);
                                    speech_counter = 0;
                                }
                                else
                                {
                                    speech_counter++;
                                }
                                line_2_appear++;
                            }
                            else if (max <= line_2_appear) // checking if this is the last character
                            {
                                line_2_appear--; // IT'S IMPORTANT TO NOT OVERFILL THIS VAR. WHATEVER YOU DO, DO NOT LET IT REACH MAX VALUE!
                                if (line_2_appear < 0)
                                {
                                    line_2_appear = 0;
                                }
                                line_2_ready = true;
                                text_sprites_2[line_2_appear].set_visible(true);
                                
                                line_2.set_one_sprite_per_character(false);
                                line_3_appear = 0;
                            }
                            
                        }
                        else // if the line is empty
                        {
                            line_2_ready = true;
                            line_3_appear = 0;
                        }
                    }
                    if (line_3_ready == false && line_1_ready == true && line_2_ready == true) // setting the next character visible
                    { 
                        max = text_sprites_3.size(); // for this function the value from the vector itself is important. For other applications use TextManager::get_length
                        if (max>0) // checking if the line is empty and should be skipped
                        {
                            
                            line_3.set_one_sprite_per_character(true);
                            if (max > line_3_appear && line_3_ready == false) // setting the next character visible
                            {
                                text_sprites_3[line_3_appear].set_visible(true);
                                if (speech_counter > 0 && frame_skip == false)
                                {
                                    bn::sound_items::speech.play(1.0);
                                    speech_counter = 0;
                                }
                                else
                                {
                                    speech_counter++;
                                }
                                line_3_appear++;
                            }
                            else if (max <= line_3_appear) // checking if this is the last character
                            {
                                line_3_appear--; // IT'S IMPORTANT TO NOT OVERFILL THIS VAR. WHATEVER YOU DO, DO NOT LET IT REACH MAX VALUE!
                                if (line_3_appear < 0)
                                {
                                    line_3_appear = 0;
                                }
                                line_3_ready = true;
                                text_sprites_3[line_3_appear].set_visible(true);
                                
                                line_3.set_one_sprite_per_character(false);
                                
                            }
                        }
                        else // if the line is empty
                        {
                            line_3_ready = true;
                        }
                        
                    }
                    
                    
                    

                    line_skip = 0;
                }
                else
                {
                    line_skip++;
                }
                
                if (line_1_ready == true && line_2_ready == true && line_3_ready == true) // Blinking the white triangle upon text completion
                    {
                        if (blink < 36)
                        {
                            textbox.set_map(bn::regular_bg_items::textbox.map_item(), 1);
                            blink++;
                        }
                        else if (blink < 72)
                        {
                            textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0);
                            blink++;
                        }
                        else
                        {
                            blink = 0;
                        }
                        
                    }
                
                    if (a_press_timeout < 5) // updating the a press timer
                    {
                        a_press_timeout++;
                    }


                

                


            
            if(bn::keypad::a_pressed())
            {
                
                if(a_press_timeout > 4)
                {
                    if (line_1_ready == false || line_2_ready == false || line_3_ready == false) // checking if text animation is over
                    {
                        if(frame_skip == false)
                        {
                            frame_skip = true;
                        }
                        else
                        {
                        anna_fade_in_flag = false; // fixing a flag
                        anna_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                        line_change = true; // triggers the text change
                        current_index += 3; // offsets the line index
                        a_press_timeout = 0; // resets the a press timeout
                        anna_anim = 0; // resets the talking animation var
                        line_1_appear = 0;
                        line_2_appear = 0;
                        line_3_appear = 0;
                        line_1_ready = false;
                        line_2_ready = false;
                        line_3_ready = false;
                        text_sprites_1.clear();
                        textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0); // blinking ends
                        blink = 0;
                        frame_skip = false;
                        }
                    }
                    else
                    {
                        anna_fade_in_flag = false; // fixing a flag
                        anna_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                        sit_memory = TextManager::get_situation(current_index/3,0);
                        line_change = true; // triggers the text change
                        current_index += 3; // offsets the line index
                        a_press_timeout = 0; // resets the a press timeout
                        anna_anim = 0; // resets the talking animation var
                        line_1_appear = 0;
                        line_2_appear = 0;
                        line_3_appear = 0;
                        line_1_ready = false;
                        line_2_ready = false;
                        line_3_ready = false;
                        text_sprites_1.clear();
                        textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0); // blinking ends
                        blink = 0;
                        frame_skip = false;
                    }
                }
                        

                 
                
            }
            
            
            //info.update();
            bn::core::update();
        }
        if (current_index >= 44)
            {
                day = 1;
                activity = 1;
                // break;
            }
    }

    void day_1()
    {
        int t = 0;
        int occasion = 0;
        int current_index = 45;
        int karmotrine_delta = karmotrine_memory - karmotrine_prev;
        switch(pos)
        {
            case 0:
                current_index = 45;
            break;

            case 1:
                if(order == 21 || order == 42)
                {
                    occasion = 1;
                    current_index = 198;
                    karmotrine_memory = 0;
                }
                else if(order == 17) // CHANGE THE VARS, THIS IS PIANO MAN
                {
                    occasion = 7;
                    pos = 2; // keeping up with the rest of the scenarios
                    current_index = 276;
                    karmotrine_memory = 0;
                }
                else
                {
                    occasion = 2;
                    current_index = 189;
                    karmotrine_memory = 0;
                }
            break;

            case 2:
                if(order == 16 || order == 40)
                {
                    occasion = 3;
                    current_index = 264;
                    karmotrine_memory = 0;
                }
                else
                {
                    occasion = 4;
                    current_index = 249;
                    karmotrine_memory = 0;
                }
            break;

            case 3:
                if (order == 27) // big beer - advance
                {
                    occasion = 20;
                    current_index = 576;//
                    pos = 6;
                }
                else if (order == 2) // beer - redo the drink
                {
                    occasion = 10;
                    current_index = 516;
                    pos = 4;
                }
                else if (karmotrine_delta == 0) // no alcohol - redo the drink
                {
                    occasion = 9;
                    current_index = 441;
                    
                }
                else // wrong drink - advance
                {
                    occasion = 19;
                    current_index = 501;
                    pos = 6;
                }
            break;

            case 4:
                if (order == 2) // normal beer - advance
                {
                    occasion = 13;
                    current_index = 480;
                    pos = 6;
                }
                else if (order == 27) // big beer - advance
                {
                    occasion = 14;
                    current_index = 489;
                    pos = 6;
                }
                else if (karmotrine_delta == 0) // no alcohol - advance
                {
                    occasion = 11;
                    current_index = 465;
                    pos = 6;
                }
                else // wrong drink - advance
                {
                    occasion = 19;
                    current_index = 501;
                    pos = 6;
                }
            break;

            case 5:
                if (order == 2) // normal beer - advance
                {
                    occasion = 15;
                    current_index = 558;
                    pos = 6;
                }
                else if (order == 27) // big beer - advance
                {
                    occasion = 16;
                    current_index = 567;
                    pos = 6;
                }
                else if (karmotrine_delta == 0) // no alcohol - advance
                {
                    occasion = 17;
                    current_index = 534;
                    pos = 6;
                }
                else // wrong drink - advance
                {
                    occasion = 18;
                    current_index = 546;
                    pos = 6;
                }
            break;

            case 7:
                if (order == 2) // normal beer - advance
                {
                    occasion = 21;
                    current_index = 792;
                }
                else if (order == 27) // big beer - advance
                {
                    occasion = 22;
                    current_index = 804;
                }
                else if (karmotrine_delta == 0) // no alcohol - advance
                {
                    occasion = 23;
                    current_index = 762;
                }
                else // wrong drink - advance
                {
                    occasion = 24;
                    current_index = 777;
                }

                if(karmotrine_memory > 17)
                {
                    drunk = true;
                }
            break;

            case 8: // donovan order 3 not drunk
                
                if (order == 2) // normal beer - advance
                {
                    occasion = 25;
                    current_index = 1113;
                    pos++;
                }
                else if (order == 27) // big beer - advance
                {
                    occasion = 26;
                    current_index = 1122;
                    pos++;
                }
                else if (karmotrine_delta == 0) // no alcohol - advance
                {
                    occasion = 27;
                    current_index = 1089;
                    pos++;
                }
                else // wrong drink - advance
                {
                    occasion = 28;
                    current_index = 1101;
                    pos++;
                }

                if(karmotrine_memory > 17)
                {
                    drunk = true;
                }
            break;

            case 9: // donovan order 3 drunk
                if (karmotrine_delta == 0) // non-alco
                {
                   if(order > 25 && order < 46) // big
                    {
                        if (order == 44 || order == 41 || order == 45 || order == 37 || order == 38 ) // big bitter non-alco drink
                        {
                            occasion = 29;
                            current_index = 1278;
                        }
                        else // big not bitter non alco drink
                        {
                            occasion = 30;
                            current_index = 1287;
                        }
                    }
                    else // small non alco drink
                    {
                        occasion = 31;
                        current_index = 1266;
                    }
                }
                else // alco
                {
                    occasion = 32;
                    current_index = 1296;
                }
            break;

            case 10: // ingram order 1
                if (order == 5 || order == 6 || order == 5 || order == 16 || order == 18 || order == 20 || order == 21 || order == 30 || order == 31 || order == 40 || order == 42 || order == 43) // sweet
                {
                    occasion = 34;
                    current_index = 1368;
                    ingr[0] = 1; // remember the drink
                }
                else if (order == 38 || order == 13) // gut punch
                {
                    occasion = 35;
                    current_index = 1389;
                    ingr[0] = 2; // remember the drink
                }
                else // other
                {
                    occasion = 33;
                    current_index = 1353;
                    ingr[0] = 0; // remember the drink
                }
            break;

            case 11: // ingram drink 2
                if (order == 5 || order == 6 || order == 5 || order == 16 || order == 18 || order == 20 || order == 21 || order == 30 || order == 31 || order == 40 || order == 42 || order == 43) // sweet
                {
                    occasion = 36;
                    current_index = 1575;
                    ingr[1] = 1;
                }
                else if (order == 45 || order == 23) // suplex
                {
                    occasion = 37;
                    current_index = 1611;
                    ingr[1] = 3; // remember the drink
                }
                else if (order == 41 || order == 19) // piledriver
                {
                    occasion = 38;
                    current_index = 1626;
                    ingr[1] = 2; // remember the drink
                }
                else // other
                {
                    occasion = 39;
                    current_index = 1632;
                    ingr[1] = 0; // remember the drink
                }
            break;

            case 12: // ingram drink 3
                if (order == 5 || order == 6 || order == 5 || order == 16 || order == 18 || order == 20 || order == 21 || order == 30 || order == 31 || order == 40 || order == 42 || order == 43) // sweet
                {
                    occasion = 40;
                    current_index = 1710;
                    ingr[2] = 1;
                }
                else if (order == 35 || order == 10) // piledriver
                {
                    occasion = 41;
                    current_index = 1719;
                    ingr[2] = 2; // remember the drink
                }
                else // other
                {
                    occasion = 42;
                    current_index = 1725;
                    ingr[2] = 0; // remember the drink
                }
            break;

            // case 6:

                
                
                
        }
         // calculated index
        karmotrine_prev = karmotrine_memory;
        int line_1_index = 0; 
        int line_2_index = 0;
        int line_3_index = 0;
        bool line_change = true; // action flag for changing the text and the situation
        int a_press_timeout = 0; // timeout for the a button

        int gil_x = 0; //  abg coordinates
        int gil_y = -10; //  abg coordinates
        int _gil_x = 0; //  temp coord
        int ch1_anim; // counter for the talking animation
        int ch1_blink_time = 180; // stores the current timer for the blinking
        int ch1_blink_count = 0; // counts up till the next blink
        int ch1_blinking = 0; // counts up till the end of blinking
        bool ch1_blink_flag = false;

        int dana_x = 0; //  abg coordinates
        int dana_y = -10; //  abg coordinates
        int ch2_anim; // counter for the talking animation
        int ch2_blink_time = 180; // stores the current timer for the blinking
        int ch2_blink_count = 0; // counts up till the next blink
        int ch2_blinking = 0; // counts up till the end of blinking
        bool ch2_blink_flag = false;

        bool fade_in_flag = false; // says if abg is fading in
        bn::fixed fade_in_intensity = 1.0; // starting alpha value
        int anna_tv_counter = 0;
        int anna_tv_timer = 0;
        
        bn::random random;
        int line_1_appear = 0;
        int line_2_appear = 0;
        int line_3_appear = 0;
        bool line_1_ready = false;
        bool line_2_ready = false;
        bool line_3_ready = false;
        int line_1_length = 0;
        int max = 0;
        int line_skip = 0;
        int est_time = 0;
        int sym_sum = 0;
        int blink = 0; // timer for blinking the triangle
        bool frame_skip = false; // frame skipping flag for text generation
        int sit_memory = 0;
        constexpr int tv_x = 24;
        constexpr int tv_y = -61;
        int fan_rot = 0; // rotation var for the fan
        int speech_counter = 0;
        int current_situation = 0;
        //int fade_in_intensity = 0;
        bool setup_flag = true; // a flag for determening the character on the screen
        
        

        bn::sprite_text_generator line_1(common::variable_8x8_sprite_font);
        bn::sprite_text_generator line_2(common::variable_8x8_sprite_font);
        bn::sprite_text_generator line_3(common::variable_8x8_sprite_font);
 
        line_1.set_left_alignment();
        line_2.set_left_alignment();
        line_3.set_left_alignment();
        line_1.set_bg_priority(1);
        line_2.set_bg_priority(1);
        line_3.set_bg_priority(1);


        bn::vector<bn::sprite_ptr, 64> text_sprites_1;
        bn::vector<bn::sprite_ptr, 64> text_sprites_2;
        bn::vector<bn::sprite_ptr, 64> text_sprites_3;


        bn::string_view line1 = TextManager::get_line(0,1);
        bn::string_view line2 = TextManager::get_line(1,1);
        bn::string_view line3 = TextManager::get_line(2,1);


        // line_1.generate(-112, 48, line1, text_sprites_1);
        // line_2.generate(-112, 60, line2, text_sprites_2);
        // line_3.generate(-112, 72, line3, text_sprites_3);

        bn::vector<bn::sprite_ptr, 20> flanergide_vector;
        

        //bn::music_items::hopesanddreams.play();
        if(play_flag == false)
        {
            bn::music_items::dusk.play(0.3,true);
            play_flag = true;
        }
        



        
        bn::regular_bg_ptr bg_bg = bn::regular_bg_items::bg.create_bg(0, -15);
        bn::regular_bg_ptr textbox = bn::regular_bg_items::textbox.create_bg(8, -48);
        textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0);
        bg_bg.set_priority(3);
        textbox.set_priority(3);
        bn::sprite_ptr fan = bn::sprite_items::fan.create_sprite(tv_x - 50, tv_y - 3);
        fan.set_visible(true);
        fan.set_bg_priority(0);

        bn::regular_bg_ptr character1 = bn::regular_bg_items::gil.create_bg(gil_x, gil_y);
        character1.set_priority(1);
        
        bn::sprite_ptr kimsleep_1 = bn::sprite_items::kim_spr.create_sprite(gil_x - 35, gil_y - 24);
        bn::sprite_ptr kimsleep_2 = bn::sprite_items::kim_spr.create_sprite(gil_x - 35, gil_y + 40);
        kimsleep_2.set_tiles(bn::sprite_items::kim_spr.tiles_item(),1);
        kimsleep_1.set_bg_priority(2);
        kimsleep_2.set_bg_priority(2);
        bn::regular_bg_ptr character2 = bn::regular_bg_items::dana.create_bg(gil_x - 60, gil_y);
        character2.set_priority(1);
        kimsleep_1.set_visible(false);
        kimsleep_2.set_visible(false);
        character2.set_visible(false);
        //gil_abg.set_wrapping_enabled(0);

        bn::sprite_ptr ch1_eyes = bn::sprite_items::gil_eyes.create_sprite(gil_x - 1, gil_y - 23);
        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
        ch1_eyes.set_bg_priority(0);
        ch1_eyes.set_visible(false);
        bn::sprite_ptr ch1_mouth = bn::sprite_items::gil_mouth.create_sprite(gil_x, gil_y - 8);
        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
        ch1_mouth.set_bg_priority(0);
        ch1_mouth.set_visible(false);
        bn::sprite_ptr dana_eyes = bn::sprite_items::dana_eyes.create_sprite(gil_x - 62, gil_y - 12);
        dana_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
        dana_eyes.set_bg_priority(0);
        dana_eyes.set_visible(false);
        bn::sprite_ptr dana_mouth = bn::sprite_items::dana_mouth.create_sprite(gil_x - 59, gil_y + 1);
        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
        dana_mouth.set_bg_priority(0);
        dana_mouth.set_visible(false);

        character1.set_item(bn::regular_bg_items::donovan);
        bn::bg_palette_ptr donovan_palette = character1.palette();
        character1.set_item(bn::regular_bg_items::ingram);
        bn::bg_palette_ptr ingram_palette = character1.palette();
        character1.set_item(bn::regular_bg_items::gil);
        bn::bg_palette_ptr gil_palette = character1.palette();
        character2.set_item(bn::regular_bg_items::dana);
        bn::bg_palette_ptr dana_palette = character2.palette();
        bn::sprite_palette_ptr kimsleep_palette = kimsleep_1.palette();

        bn::sprite_ptr anna_tv = bn::sprite_items::anna_tv.create_sprite(tv_x, tv_y);
        anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),0);
        anna_tv.set_bg_priority(2);
        anna_tv.set_visible(false);

        

        

        while(current_situation != 666 && current_situation != 667)
        
        // while(! bn::keypad::start_pressed())
        {
            switch(occasion)
            {
                case 2:
                    if (current_index == 198)
                    {
                        current_index += 12;
                    }
                break;

                case 3:
                    if (current_index == 276)
                    {
                        current_index += 9;
                    }
                break;

                case 4:
                    if (current_index == 264)
                    {
                        current_index += 21;
                    }
                break;

                case 11:
                    if (current_index == 480)
                    {
                        current_index += 105;
                    }
                break;

                case 12:
                    if (current_index == 513)
                    {
                        current_index += 72;
                    }
                break;

                case 13:
                    if (current_index == 489)
                    {
                        current_index += 96;
                    }
                break;

                case 14:
                    if (current_index == 498)
                    {
                        current_index += 87;
                    }
                break;

                // case 10:
                //     if (current_index == 535)
                //     {
                //         current_index += 44;
                //     }
                // break;

                case 15:
                    if (current_index == 567)
                    {
                        current_index += 18;
                    }
                break;

                case 16:
                    if (current_index == 576)
                    {
                        current_index += 9;
                    }
                break;

                case 17:
                    if (current_index == 546)
                    {
                        current_index += 39;
                    }
                break;

                case 18:
                    if (current_index == 555)
                    {
                        current_index += 27;
                    }
                break;

                case 19:
                    if (current_index == 513)
                    {
                        current_index += 72;
                    }
                break;

                case 21: // Donovan 2 Beer
                    if (current_index == 804)
                    {
                        current_index += 15;
                    }
                    if (drunk == true)
                    {
                    if (current_index == 1077) // skipping to the bitter thing
                    {
                        current_index += 174;
                        pos++;
                    }
                    }
                break;
                
                case 22:
                    if (drunk == true)
                    {
                    if (current_index == 1077) // skipping to the bitter thing
                    {
                        current_index += 174;
                        pos++;
                    }
                    }
                    
                break;
                // case 22: // Donovan 2 Beer
                //     if (current_index == 789)
                //     {
                //         current_index += 27;
                //     }
                // break;

                case 23: // Donovan nonalco
                    if (current_index == 777)
                    {
                        current_index += 42;
                    }
                    if (drunk == true)
                    {
                    if (current_index == 1077) // skipping to the bitter thing
                    {
                        current_index += 174;
                        pos++;
                    }
                    }
                break;

                case 24: // Donovan 2 wrong
                    if (current_index == 792)
                    {
                        current_index += 27;
                    }
                    if (drunk == true)
                    {
                    if (current_index == 1077) // skipping to the bitter thing
                    {
                        current_index += 174;
                        pos++;
                    }
                    }
                break;

                case 25: // Donovan 3 Beer
                    if (drunk == false)
                    {
                        if (current_index == 1122)
                        {
                            current_index += 54;
                        }
                        if (current_index == 1176)
                        {
                            current_index += 132;
                        }
                    }
                    else
                    {
                        if (current_index == 1122)
                        {
                            current_index += 54;
                        }
                        if (current_index == 1251)
                        {
                            current_index += 57;
                        }
                    }
                break;

                case 26: // Donovan 3 Beer
                    if (drunk == false)
                    {
                        if (current_index == 1131)
                        {
                            current_index += 45;
                        }
                        if (current_index == 1176)
                        {
                            current_index += 132;
                        }
                    }
                    else
                    {
                        if (current_index == 1131)
                        {
                            current_index += 45;
                        }
                        if (current_index == 1251)
                        {
                            current_index += 57;
                        }
                    }
                break;

                case 27: // Donovan 3 nonalco
                    if (current_index == 1101)
                      {
                        current_index += 30;
                      }
                    if (current_index == 1176)
                        {
                            current_index += 132;
                        }
                break;

                case 28: // Donovan 3 wrong
                    

                    if (drunk == false)
                    {
                        if (current_index == 1113)
                        {
                            current_index += 18;
                        }
                        if (current_index == 1176)
                        {
                            current_index += 132;
                        }
                    }
                    else
                    {
                        if (current_index == 1113)
                        {
                            current_index += 63;
                        }
                        if (current_index == 1251)
                        {
                            current_index += 57;
                        }
                    }
                break;

                case 29: // Donovan 3-2 big bitter non-alco
                    if (current_index == 1287)
                    {
                        current_index -= 111;
                    }
                    if (current_index == 1251)
                    {
                        current_index += 57;
                    }
                break;

                case 30: // Donovan 3-2 big not bitter non-alco
                    if (current_index == 1296)
                    {
                        current_index -= 120;
                    }
                    if (current_index == 1251)
                    {
                        current_index += 57;
                    }
                break;

                case 31: // Donovan 3-2 smol non-alco
                    if (current_index == 1278)
                    {
                        current_index -= 102;
                    }
                    if (current_index == 1251)
                    {
                        current_index += 57;
                    }
                break;

                case 32: // Donovan 3-2 alco
                    if (current_index == 1308)
                    {
                        current_index -= 132;
                    }
                    if (current_index == 1251)
                    {
                        current_index += 57;
                    }
                break;

                case 33: // Ingram 1 other
                    if (current_index == 1368)
                    {
                        current_index += 30;
                    }
                    if (current_index == 1422) // skipping the sweet ingram
                    {
                        current_index += 3;
                    }
                break;

                case 34: // Ingram 1 sweet
                    if (current_index == 1389)
                    {
                        current_index += 9;
                    }
                    if (current_index == 1410) // skipping the non sweet ingram
                    {
                        current_index += 12;
                    }
                break;

                case 35: // Ingram 1 gut punch
                    if (current_index == 1422) // skipping the sweet ingram
                    {
                        current_index += 3;
                    }
                    
                break;

                case 36: // Ingram 2 sweet
                    if (ingr[0] != 1 && current_index == 1584) // skipping the sweet ingram
                    {
                        current_index += 54;
                    }
                    else if (current_index == 1611)
                    {
                        current_index += 81;
                    }
                break;

                case 37: // Ingram 2 suplex
                    if (current_index == 1626)
                    {
                        current_index += 12;
                    }
                break;

                case 38: // Ingram 2 piledriver
                    if (current_index == 1611)
                    {
                        current_index += 6;
                    }
                break;

                case 40: // Ingram 3 sweet
                    if (ingr[0] != 1 && ingr[1] != 1 && current_index == 1725) // skipping the sweet ingram
                    {
                        current_index += 12;
                    }
                    else if (current_index == 1719)
                    {
                        current_index += 102;
                    }

                    if (ingr[0] != 1 && ingr[1] != 1 && current_index == 1821) // UPDATE
                    {
                        current_index += 153;
                    }
                break;

                case 41: // Ingram 3 fringe
                    if (current_index == 1725)
                    {
                        current_index += 6;
                    }
                    if (current_index == 1821)
                    {
                        current_index += 153;
                    }
                break;

                case 42: // Ingram 3 fringe
                    if (current_index == 1821)
                    {
                        current_index += 153;
                    }
                break;

                // case 20:
                //     if (current_index == 573)
                //     {
                //         current_index += 99;
                //     }
                // break;
            }
            line = current_index + 3;
            line_1_index = current_index;
            line_2_index = current_index + 1;
            line_3_index = current_index + 2;

            if (line_change == true) // generating new text
            {
                text_sprites_1.clear();
                text_sprites_2.clear();
                text_sprites_3.clear();


                bn::string_view line1 = TextManager::get_line(line_1_index,1); // looking up line data
                bn::string_view line2 = TextManager::get_line(line_2_index,1);
                bn::string_view line3 = TextManager::get_line(line_3_index,1);

                

                line_1_length = TextManager::get_length(line_1_index,1);
                //line_1_length -= 5;

                line_1.set_one_sprite_per_character(true); // first line is being drawn
                line_2.set_one_sprite_per_character(true); // the rest are not one sprite per character until it's their turn
                line_3.set_one_sprite_per_character(true);
                line_1.generate(-115, 48, line1, text_sprites_1); // generating a new line
                line_1_appear = 0;
                line_2.generate(-115, 60, line2, text_sprites_2);
                line_3.generate(-115, 72, line3, text_sprites_3);
                line_1.set_visible(false); // making all lines invisible
                line_2.set_visible(false);
                line_3.set_visible(false);


                sym_sum = TextManager::get_length(line_1_index,1) + TextManager::get_length(line_2_index,1) + TextManager::get_length(line_3_index,1);
                est_time = sym_sum/20;
                est_time--;
                if (est_time<=2)
                {
                    est_time = 2;
                }

                
                //char buffer[10];
                
                
                line_change = false;
            }


                current_situation = TextManager::get_situation(current_index/3,1);
                switch (current_situation) // Making stuff happen based on the according Situations var
                {
                    case 0: // bargroud
                        character1.set_visible(false);
                        ch1_eyes.set_visible(false);
                        ch1_mouth.set_visible(false);
                        donovan_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                    break;
                        
                    // case 1: // anna TV
                    //     anna_abg.set_visible(false);
                    //     anna_eyes.set_visible(false);
                    //     anna_mouth.set_visible(false);
                    //     anna_tv.set_visible(true);

                    //     if (anna_tv_counter < 5)
                    //     {
                    //             anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),0);
                    //             anna_tv_counter++;
                    //             anna_tv_timer++;
                    //     }

                    //     else if (anna_tv_counter < 10)
                    //     {
                    //             anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),1);
                    //             anna_tv_counter++;
                    //             anna_tv_timer++;
                    //     }

                    //     else if (anna_tv_counter < 15)
                    //     {
                    //             anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),2);
                    //             anna_tv_counter++;
                    //             anna_tv_timer++;
                    //     }

                    //     else if (anna_tv_counter < 20)
                    //     {
                    //             anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),3);
                    //             anna_tv_counter++;
                    //             anna_tv_timer++;
                    //     }

                    //     else if (anna_tv_counter < 25)
                    //     {
                    //             anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),4);
                    //             anna_tv_counter++;
                    //             anna_tv_timer++;
                    //     }

                    //     else if (anna_tv_counter < 30)
                    //     {
                    //             anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),5);
                    //             anna_tv_counter++;
                    //             anna_tv_timer++;
                    //     }
                    //     else
                    //     {
                    //         anna_tv_counter = 0;
                    //     }
                        
                        
                    //     if (anna_tv_timer > 360)
                    //     {
                    //         anna_tv.set_visible(false);
                    //     }
                    //     sit_memory == 1;
                    // break;

                    case 11: // normal gil talking
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    ch1_eyes.set_position(-1,-33);
                    ch1_mouth.set_position(0,-18);
                    }
                    
                        if (sit_memory == 0 || sit_memory == 1)
                    {
                        character2.set_visible(false);
                        character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                        anna_tv.set_visible(false);
                        character1.set_visible(false);
                        fade_in_flag = true;
                        character1.set_x(gil_x);
                        character1.set_y(gil_y);
                        gil_palette.set_fade_intensity(1.0);
                        character1.set_visible(true);
                        sit_memory = 2;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -= 0.01;
                            if(fade_in_intensity<0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            gil_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    
                }

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            
                    break;

                    case 12: // normal gil silent
                    
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    gil_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    fade_in_flag = false; // Preventing a fade in effect
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                    gil_x = 0;
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    ch1_mouth.set_x(gil_x);
                    ch1_eyes.set_x(gil_x - 1);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                
                }
                    break;

                case 13: // fucked up gil silent
                        
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    gil_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    fade_in_flag = false; // Preventing a fade in effect
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 3);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),8);
                    ch1_blink_count++;
                    
                    break;

                case 14: // gil cods talking

                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    gil_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    fade_in_flag = false; // Preventing a fade in effect
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 2);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),3);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),5);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),3);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),3);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),5);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),3);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),3);
                    }
                    
                

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),3);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),2);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            
                    break;

                case 15: // gil cods silent
                    
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    gil_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    fade_in_flag = false; // Preventing a fade in effect
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 2);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),3);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),3);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),2);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                
                }
                    break;

                case 16: // fucked up gil talking
                        
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    //kim_spr.set_visible(false);
                    gil_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    fade_in_flag = false; // Preventing a fade in effect
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 3);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),8);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
            
                    break;

                    case 17: // normal gil silent anna tv
                    
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    gil_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    fade_in_flag = false; // Preventing a fade in effect
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                
                }

                anna_tv.set_visible(true);

                        if (anna_tv_counter < 4)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),0);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }

                        else if (anna_tv_counter < 7)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),1);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }

                        else if (anna_tv_counter < 12)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),2);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }

                        else if (anna_tv_counter < 15)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),3);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }

                        else if (anna_tv_counter < 17)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),4);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }

                        else if (anna_tv_counter < 20)
                        {
                                anna_tv.set_tiles(bn::sprite_items::anna_tv.tiles_item(),5);
                                anna_tv_counter++;
                                anna_tv_timer++;
                        }
                        else
                        {
                            anna_tv_counter = 0;
                        }
                        
                        
                        if (anna_tv_timer > 360)
                        {
                            anna_tv.set_visible(false);
                        }

                    break;

                    case 18: // surprised gil talking
                        
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    gil_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 1);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    
                

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),5);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),4);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            
                    break;

                    case 19: // surprised gil silent
                    
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    gil_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    fade_in_flag = false; // Preventing a fade in effect
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 1);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),5);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),4);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                
                }
                    break;

                case 31: // dana and kim on the left silent, gil on the right silent
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }
                        if (sit_memory == 12)
                    {
                        character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                        character2.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        
                        character2.set_visible(false); // making sure they're off
                        kimsleep_1.set_visible(false);
                        kimsleep_2.set_visible(false);
                        ch1_eyes.set_visible(false);
                        ch1_mouth.set_visible(false);

                        fade_in_flag = true;
                        // gil.set_x(gil_x);
                        // gil.set_y(gil_y);
                        dana_palette.set_fade_intensity(1.0); // making them dark
                        kimsleep_palette.set_fade_intensity(1.0);
                        character2.set_visible(true); // turning them back on
                        kimsleep_1.set_visible(true);
                        kimsleep_2.set_visible(true);
                        sit_memory = 31;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            
                            if(_gil_x >= 40) // sliding gil to the right
                            {
                                _gil_x = 40;
                            }
                            else
                            {
                                _gil_x ++;
                            }

                            fade_in_intensity -= 0.01;
                            if(fade_in_intensity<0.0)
                            {
                                fade_in_intensity = 0.0;
                                
                            }
                            dana_palette.set_fade_intensity(fade_in_intensity);
                            kimsleep_palette.set_fade_intensity(fade_in_intensity);
                            character1.set_x(_gil_x);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    dana_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    kimsleep_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                    gil_x = 40;
                    character1.set_x(gil_x);
                    ch1_mouth.set_x(40);
                    ch1_eyes.set_x(39);
                    //gil.set_y(gil_y);
                    character2.set_visible(true);
                    kimsleep_1.set_visible(true);
                    kimsleep_2.set_visible(true);
                    
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    dana_mouth.set_visible(true);
                    dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    dana_eyes.set_visible(true);
                    ch1_blink_count++;
                    ch2_blink_count++;

                    // if(gil_anim<=est_time)
                    //     {
                    //     if(t<9)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    // }
                    // else if(t<18)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    // }
                    // else if(t<27)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    // }
                    // else if(t<36)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    // }
                    // else if(t<45)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    // }
                    // else if(t<54)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    // }
                    // else if(t<63)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    // }
                    // else if(t<72)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    // }
                    // else
                    // {
                    //     t=0;
                    //     gil_anim++;
                    // };
                // }
                //     else
                //     {
                //         gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                //     }
                    
                //}

                    if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                    {
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_flag = true;
                    }
                    if (ch1_blink_flag == true)
                    {
                        ch1_blink_count++;
                        if (ch1_blink_count >= 27)
                        {
                            
                            ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_time = random.get_int(180, 600);
                            ch1_blink_flag = false;
                        }
                    }
                    if (ch2_blink_count >= ch2_blink_time && ch2_blink_flag == false) // blinking
                    {
                        dana_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),1);
                        ch2_anim = 0;
                        ch2_blink_count = 0;
                        ch2_blink_flag = true;
                    }
                    if (ch2_blink_flag == true)
                    {
                        ch2_blink_count++;
                        if (ch2_blink_count >= 27)
                        {
                            
                            dana_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                            ch2_anim = 0;
                            ch2_blink_count = 0;
                            ch2_blink_time = random.get_int(180, 600);
                            ch2_blink_flag = false;
                        }
                    }
                }
                break;

                case 32: // dana and kim on the left talking, gil on the right silent
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }
                    //     if (sit_memory == 12)
                    // {
                    //     gil.set_map(bn::regular_bg_items::gil.map_item(), 0);
                    //     dana.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        
                    //     dana.set_visible(false); // making sure they're off
                    //     kimsleep_1.set_visible(false);
                    //     kimsleep_2.set_visible(false);
                    //     gil_eyes.set_visible(false);
                    //     gil_mouth.set_visible(false);

                    //     fade_in_flag = true;
                    //     // gil.set_x(gil_x);
                    //     // gil.set_y(gil_y);
                    //     dana_palette.set_fade_intensity(1.0); // making them dark
                    //     kimsleep_palette.set_fade_intensity(1.0);
                    //     dana.set_visible(true); // turning them back on
                    //     kimsleep_1.set_visible(true);
                    //     kimsleep_2.set_visible(true);
                    //     sit_memory = 31;
                    // }
                    // else if (fade_in_flag == true)
                    // {
                    //     if (fade_in_intensity > 0.0)
                    //     {
                            
                    //         if(_gil_x >= 40) // sliding gil to the right
                    //         {
                    //             _gil_x = 40;
                    //         }
                    //         else
                    //         {
                    //             _gil_x ++;
                    //         }

                    //         fade_in_intensity -= 0.01;
                    //         if(fade_in_intensity<0.0)
                    //         {
                    //             fade_in_intensity = 0.0;
                                
                    //         }
                    //         dana_palette.set_fade_intensity(fade_in_intensity);
                    //         kimsleep_palette.set_fade_intensity(fade_in_intensity);
                    //         gil.set_x(_gil_x);
                    //     }
                    //     else
                    //     {
                    //         fade_in_flag = false;
                    //     }
                    // }
                    // else
                    // {
                    dana_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    kimsleep_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                    gil_x = 40;
                    character1.set_x(gil_x);
                    ch1_mouth.set_x(40);
                    ch1_eyes.set_x(39);
                    //gil.set_y(gil_y);
                    character2.set_visible(true);
                    kimsleep_1.set_visible(true);
                    kimsleep_2.set_visible(true);
                    
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    dana_mouth.set_visible(true);
                    dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    dana_eyes.set_visible(true);
                    ch1_blink_count++;
                    ch2_blink_count++;

                    if(ch1_anim<=est_time)
                    {
                        if(t<9)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),2);
                    }
                    else if(t<63)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),1);
                    }
                    // else if(t<72)
                    // {
                    //     dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    // }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    }
                    }
                    else
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    
                

                    if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                    {
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_flag = true;
                    }
                    if (ch1_blink_flag == true)
                    {
                        ch1_blink_count++;
                        if (ch1_blink_count >= 27)
                        {
                            
                            ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_time = random.get_int(180, 600);
                            ch1_blink_flag = false;
                        }
                    }
                    if (ch2_blink_count >= ch2_blink_time && ch2_blink_flag == false) // blinking
                    {
                        dana_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),1);
                        ch2_anim = 0;
                        ch2_blink_count = 0;
                        ch2_blink_flag = true;
                    }
                    if (ch2_blink_flag == true)
                    {
                        ch2_blink_count++;
                        if (ch2_blink_count >= 27)
                        {
                            
                            dana_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                            ch2_anim = 0;
                            ch2_blink_count = 0;
                            ch2_blink_time = random.get_int(180, 600);
                            ch2_blink_flag = false;
                        }
                    }
                
                break;

                case 33: // dana and kim on the left silent, gil on the right talking
                    
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }

                    dana_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    kimsleep_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                    gil_x = 40;
                    character1.set_x(gil_x);
                    ch1_mouth.set_x(40);
                    ch1_eyes.set_x(39);
                    //gil.set_y(gil_y);
                    character2.set_visible(true);
                    kimsleep_1.set_visible(true);
                    kimsleep_2.set_visible(true);
                    
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    dana_mouth.set_visible(true);
                    dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    dana_eyes.set_visible(true);
                    ch1_blink_count++;
                    ch2_blink_count++;

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    
                

                    if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                    {
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_flag = true;
                    }
                    if (ch1_blink_flag == true)
                    {
                        ch1_blink_count++;
                        if (ch1_blink_count >= 27)
                        {
                            
                            ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_time = random.get_int(180, 600);
                            ch1_blink_flag = false;
                        }
                    }
                    if (ch2_blink_count >= ch2_blink_time && ch2_blink_flag == false) // blinking
                    {
                        dana_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),1);
                        ch2_anim = 0;
                        ch2_blink_count = 0;
                        ch2_blink_flag = true;
                    }
                    if (ch2_blink_flag == true)
                    {
                        ch2_blink_count++;
                        if (ch2_blink_count >= 27)
                        {
                            
                            dana_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                            ch2_anim = 0;
                            ch2_blink_count = 0;
                            ch2_blink_time = random.get_int(180, 600);
                            ch2_blink_flag = false;
                        }
                    }
                
                break;

                case 34: // dana and kim on the left fading out, gil on the right silent
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    character2.set_item(bn::regular_bg_items::dana);
                    //ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    //ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }

                        if (sit_memory == 31)
                    {
                        character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                        character2.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        
                        character2.set_visible(false); // making sure they're off
                        kimsleep_1.set_visible(false);
                        kimsleep_2.set_visible(false);
                        dana_eyes.set_visible(false);
                        dana_mouth.set_visible(false);

                        fade_in_flag = true;
                        // gil.set_x(gil_x);
                        // gil.set_y(gil_y);
                        dana_palette.set_fade_intensity(0.0); // making them not dark
                        kimsleep_palette.set_fade_intensity(0.0);
                        fade_in_intensity = 0.0;
                        character2.set_visible(true); // turning them back on
                        kimsleep_1.set_visible(true);
                        kimsleep_2.set_visible(true);
                        sit_memory = 34;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            
                            

                            fade_in_intensity += 0.01;
                            if(fade_in_intensity>1.0)
                            {
                                fade_in_intensity = 1.0;
                                
                            }
                            dana_palette.set_fade_intensity(fade_in_intensity);
                            kimsleep_palette.set_fade_intensity(fade_in_intensity);
                            
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    dana_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                    kimsleep_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                    gil_x = 40;
                    character1.set_x(gil_x);
                    ch1_mouth.set_x(40);
                    ch1_eyes.set_x(39);
                    //gil.set_y(gil_y);
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    dana_eyes.set_visible(false);
                    dana_mouth.set_visible(false);
                    
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    //gil_eyes.set_visible(true);
                    //dana_mouth.set_visible(true);
                    //dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    //dana_eyes.set_visible(true);
                    ch1_blink_count++;
                    //ch2_blink_count++;

                    // if(gil_anim<=est_time)
                    //     {
                    //     if(t<9)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    // }
                    // else if(t<18)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    // }
                    // else if(t<27)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    // }
                    // else if(t<36)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    // }
                    // else if(t<45)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    // }
                    // else if(t<54)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    // }
                    // else if(t<63)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    // }
                    // else if(t<72)
                    // {
                    //     gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    // }
                    // else
                    // {
                    //     t=0;
                    //     gil_anim++;
                    // };
                // }
                //     else
                //     {
                //         gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                //     }
                    
                //}

                    if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                    {
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_flag = true;
                        
                    }
                    if (ch1_blink_flag == true)
                    {
                        ch1_blink_count++;
                        if (ch1_blink_count >= 27)
                        {
                            
                            ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_time = random.get_int(180, 600);
                            ch1_blink_flag = false;
                        }
                    }
                }
                break;

                case 20: // normal gil silent sliding from right to center
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }

                        if (sit_memory == 34)
                    {
                        character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                        character1.set_x(gil_x);
                        character1.set_y(gil_y);
                        character1.set_visible(true);
                        sit_memory = 20;
                        dana_eyes.set_visible(false);
                        dana_mouth.set_visible(false);

                    }
                    else if (gil_x > 0)
                    {
                        gil_x--;
                        character1.set_x(gil_x);
                        ch1_mouth.set_x(gil_x);
                        ch1_eyes.set_x(gil_x - 1);
                    }
                    else
                    {
                    dana_palette.set_fade_intensity(1.0);
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    ch1_mouth.set_x(gil_x);
                    ch1_eyes.set_x(gil_x - 1);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;
                    
                }

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            
                break;

                case 21: // fucked up gil fading out
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }

                     if (sit_memory == 13)
                    {
                        character1.set_map(bn::regular_bg_items::gil.map_item(), 3);
                        
                        character1.set_visible(false); // making sure they're off
                        ch1_eyes.set_visible(false);
                        ch1_mouth.set_visible(false);

                        fade_in_flag = true;
                        gil_palette.set_fade_intensity(0.0); // making them not dark
                        fade_in_intensity = 0.0;
                        character1.set_visible(true); // turning them back on
                        sit_memory = 21;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            
                            

                            fade_in_intensity += 0.01;
                            if(fade_in_intensity>1.0)
                            {
                                fade_in_intensity = 1.0;
                                
                            }
                            gil_palette.set_fade_intensity(fade_in_intensity);
                           
                            
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    gil_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                    character1.set_visible(false);
                    ch1_eyes.set_visible(false);
                    ch1_mouth.set_visible(false);

                }
                break;

                case 22: // angry gil fading out
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }

                     if (sit_memory == 12)
                    {
                        character1.set_map(bn::regular_bg_items::gil.map_item(), 4);
                        
                        character1.set_visible(false); // making sure they're off
                        ch1_eyes.set_visible(false);
                        ch1_mouth.set_visible(false);

                        fade_in_flag = true;
                        gil_palette.set_fade_intensity(0.0); // making them not dark
                        fade_in_intensity = 0.0;
                        character1.set_visible(true); // turning them back on
                        sit_memory = 21;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            
                            

                            fade_in_intensity += 0.01;
                            if(fade_in_intensity>1.0)
                            {
                                fade_in_intensity = 1.0;
                                
                            }
                            gil_palette.set_fade_intensity(fade_in_intensity);
                           
                            
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    gil_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                    character1.set_visible(false);
                    ch1_eyes.set_visible(false);
                    ch1_mouth.set_visible(false);

                }
                break;

                case 49: // donovan normal silent
                    if (setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::donovan);
                    ch1_mouth.set_item(bn::sprite_items::donovan_mouth);
                    ch1_eyes.set_item(bn::sprite_items::donovan_eyes);
                    character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                    ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),0);
                    ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),0);
                    ch1_eyes.set_x(-5);
                    ch1_eyes.set_y(-38);
                    ch1_mouth.set_x(-5);
                    ch1_mouth.set_y(-21);
                    setup_flag = false;
                    }
                    
                    //gil_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    fade_in_flag = false; // Preventing a fade in effect
                    character1.set_item(bn::regular_bg_items::donovan);
                    character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                    gil_x = 0;
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    //gil_mouth.set_x(gil_x);
                    //gil_eyes.set_x(gil_x - 1);
                    character1.set_visible(true);
                    //gil_mouth.set_visible(true);
                    //gil_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    //gil_eyes.set_visible(true);
                    //gil_blink_count++;

                // if (gil_blink_count >= gil_blink_time && gil_blink_flag == false) // blinking
                // {
                //     gil_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                //     gil_blinking = 0;
                //     gil_blink_count = 0;
                //     gil_blink_flag = true;
                // }
                // if (gil_blink_flag == true)
                // {
                //     gil_blink_count++;
                //     if (gil_blink_count >= 27)
                //     {
                        
                //         gil_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                //         gil_blinking = 0;
                //         gil_blink_count = 0;
                //         gil_blink_time = random.get_int(180, 600);
                //         gil_blink_flag = false;
                //     }
                
                //}
                    break;

                case 48: // normal donovan talking
                    if (setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::donovan);
                    ch1_mouth.set_item(bn::sprite_items::donovan_mouth);
                    ch1_eyes.set_item(bn::sprite_items::donovan_eyes);
                    character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                    ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),0);
                    ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),0);
                    ch1_eyes.set_x(-5);
                    ch1_eyes.set_y(-38);
                    ch1_mouth.set_x(-5);
                    ch1_mouth.set_y(-21);
                    setup_flag = false;
                    }

                        if (sit_memory == 0)
                    {
                        character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                        
                        //anna_tv.set_visible(false);
                        character1.set_visible(false);
                        fade_in_flag = true;
                        character1.set_x(gil_x);
                        character1.set_y(gil_y);
                        donovan_palette.set_fade_intensity(1.0);
                        character1.set_visible(true);
                        sit_memory = 48;
                        
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -= 0.01;
                            if(fade_in_intensity<0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            donovan_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    donovan_palette.set_fade_intensity(0.0);
                    character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),1);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),2);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),1);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),0);
                    }
                    
                }

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            
                break;

                case 53: // smiling donovan talking closed
                    // if (setup_flag == true)
                    // {
                    // character1.set_item(bn::regular_bg_items::donovan);
                    // ch1_mouth.set_item(bn::sprite_items::donovan_mouth);
                    // ch1_eyes.set_item(bn::sprite_items::donovan_eyes);
                    // character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                    // ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),0);
                    // ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),0);
                    // ch1_eyes.set_x(-5);
                    // ch1_eyes.set_y(-38);
                    // ch1_mouth.set_x(-5);
                    // ch1_mouth.set_y(-21);
                    // setup_flag = false;
                    // }

                        if (sit_memory == 0)
                    {
                        character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                        
                        //anna_tv.set_visible(false);
                        character1.set_visible(false);
                        fade_in_flag = true;
                        character1.set_x(gil_x);
                        character1.set_y(gil_y);
                        donovan_palette.set_fade_intensity(1.0);
                        character1.set_visible(true);
                        sit_memory = 48;
                        
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -= 0.01;
                            if(fade_in_intensity<0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            donovan_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                        donovan_palette.set_fade_intensity(0.0);
                    character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    }
                    
                }
                ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),1);

                // if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                // {
                //     ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),1);
                //     ch1_blinking = 0;
                //     ch1_blink_count = 0;
                //     ch1_blink_flag = true;
                // }
                // else if (ch1_blink_flag == true)
                // {
                //     ch1_blink_count++;
                //     if (ch1_blink_count >= 27)
                //     {
                        
                //         ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),0);
                //         ch1_blinking = 0;
                //         ch1_blink_count = 0;
                //         ch1_blink_time = random.get_int(180, 600);
                //         ch1_blink_flag = false;
                //     }
                // }
            
                break;

                case 50: // smiling donovan silent open
                    // if (setup_flag == true)
                    // {
                    // character1.set_item(bn::regular_bg_items::donovan);
                    // ch1_mouth.set_item(bn::sprite_items::donovan_mouth);
                    // ch1_eyes.set_item(bn::sprite_items::donovan_eyes);
                    // character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                    // ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),0);
                    // ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),0);
                    // ch1_eyes.set_x(-5);
                    // ch1_eyes.set_y(-38);
                    // ch1_mouth.set_x(-5);
                    // ch1_mouth.set_y(-21);
                    // setup_flag = false;
                    // }

                    //     if (sit_memory == 0)
                    // {
                    //     character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                        
                    //     //anna_tv.set_visible(false);
                    //     character1.set_visible(false);
                    //     fade_in_flag = true;
                    //     character1.set_x(gil_x);
                    //     character1.set_y(gil_y);
                    //     donovan_palette.set_fade_intensity(1.0);
                    //     character1.set_visible(true);
                    //     sit_memory = 48;
                        
                    // }
                    // else if (fade_in_flag == true)
                    // {
                    //     if (fade_in_intensity > 0.0)
                    //     {
                    //         fade_in_intensity -= 0.01;
                    //         if(fade_in_intensity<0.0)
                    //         {
                    //             fade_in_intensity = 0.0;
                    //         }
                    //         donovan_palette.set_fade_intensity(fade_in_intensity);
                    //     }
                    //     else
                    //     {
                    //         fade_in_flag = false;
                    //     }
                    // }
                    // else
                    // {
                    donovan_palette.set_fade_intensity(0.0);
                    character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                //     if(ch1_anim<=est_time)
                //         {
                //         if(t<9)
                //     {
                //         ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                //     }
                //     else if(t<18)
                //     {
                //         ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                //     }
                //     else if(t<27)
                //     {
                //         ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                //     }
                //     else if(t<36)
                //     {
                //         ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                //     }
                //     else if(t<45)
                //     {
                //         ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                //     }
                //     else if(t<54)
                //     {
                //         ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                //     }
                //     else if(t<63)
                //     {
                //         ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                //     }
                //     else if(t<72)
                //     {
                //         ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                //     }
                //     else
                //     {
                //         t=0;
                //         ch1_anim++;
                //     };
                // }
                //     else
                //     {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    //}
                    
                //}
                //ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),0);

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            
                break;

                case 51: // smiling donovan silent closed
                    donovan_palette.set_fade_intensity(0.0);
                    character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    
                    
                
                ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),1);

                
            
                break;

                case 52: // smiling donovan talking open
                    // if (setup_flag == true)
                    // {
                    // character1.set_item(bn::regular_bg_items::donovan);
                    // ch1_mouth.set_item(bn::sprite_items::donovan_mouth);
                    // ch1_eyes.set_item(bn::sprite_items::donovan_eyes);
                    // character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                    // ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),0);
                    // ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),0);
                    // ch1_eyes.set_x(-5);
                    // ch1_eyes.set_y(-38);
                    // ch1_mouth.set_x(-5);
                    // ch1_mouth.set_y(-21);
                    // setup_flag = false;
                    // }

                    //     if (sit_memory == 0)
                    // {
                    //     character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                        
                    //     //anna_tv.set_visible(false);
                    //     character1.set_visible(false);
                    //     fade_in_flag = true;
                    //     character1.set_x(gil_x);
                    //     character1.set_y(gil_y);
                    //     donovan_palette.set_fade_intensity(1.0);
                    //     character1.set_visible(true);
                    //     sit_memory = 48;
                        
                    // }
                    // else if (fade_in_flag == true)
                    // {
                    //     if (fade_in_intensity > 0.0)
                    //     {
                    //         fade_in_intensity -= 0.01;
                    //         if(fade_in_intensity<0.0)
                    //         {
                    //             fade_in_intensity = 0.0;
                    //         }
                    //         donovan_palette.set_fade_intensity(fade_in_intensity);
                    //     }
                    //     else
                    //     {
                    //         fade_in_flag = false;
                    //     }
                    // }
                    // else
                    // {
                    donovan_palette.set_fade_intensity(0.0);
                    character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),4);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::donovan_mouth.tiles_item(),3);
                    }
                    
                //}
                //ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),0);

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::donovan_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            
                break;

                case 54: // normal donovan fading out
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::donovan);
                    ch1_mouth.set_item(bn::sprite_items::donovan_mouth);
                    ch1_eyes.set_item(bn::sprite_items::donovan_eyes);
                    setup_flag = false;
                    }

                     if (sit_memory == 49)
                    {
                        character1.set_map(bn::regular_bg_items::donovan.map_item(), 0);
                        
                        character1.set_visible(false); // making sure they're off
                        ch1_eyes.set_visible(false);
                        ch1_mouth.set_visible(false);

                        fade_in_flag = true;
                        donovan_palette.set_fade_intensity(0.0); // making them not dark
                        fade_in_intensity = 0.0;
                        character1.set_visible(true); // turning them back on
                        sit_memory = 54;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            
                            

                            fade_in_intensity += 0.01;
                            if(fade_in_intensity>1.0)
                            {
                                fade_in_intensity = 1.0;
                                
                            }
                            donovan_palette.set_fade_intensity(fade_in_intensity);
                           
                            
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    donovan_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                    character1.set_visible(false);
                    ch1_eyes.set_visible(false);
                    ch1_mouth.set_visible(false);

                }
                break;

                case 64: // ingram talking
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::ingram);
                    character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                    ch1_mouth.set_item(bn::sprite_items::ingram_mouth);
                    ch1_eyes.set_item(bn::sprite_items::ingram_eyes);
                    setup_flag = false;
                    ch1_eyes.set_position(28,-30);
                    ch1_mouth.set_position(33,-11);
                    }
                    
                        if (sit_memory == 0)
                    {
                        character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                        anna_tv.set_visible(false);
                        character1.set_visible(false);
                        fade_in_flag = true;
                        character1.set_x(gil_x);
                        character1.set_y(gil_y);
                        ingram_palette.set_fade_intensity(1.0);
                        character1.set_visible(true);
                        sit_memory = 2;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -= 0.01;
                            if(fade_in_intensity<0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            ingram_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    ingram_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;
                    // ch1_eyes.set_position(-1,-33);
                    // ch1_mouth.set_position(0,-18);

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),2);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);
                    }
                    
                }

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::ingram_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::ingram_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            
                break;

                case 65: // ingram silent
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::ingram);
                    ch1_mouth.set_item(bn::sprite_items::ingram_mouth);
                    ch1_eyes.set_item(bn::sprite_items::ingram_eyes);
                    setup_flag = false;
                    ch1_eyes.set_position(28,-30);
                    ch1_mouth.set_position(33,-11);
                    }
                    
                        if (sit_memory == 0 || sit_memory == 1)
                    {
                        character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                        anna_tv.set_visible(false);
                        character1.set_visible(false);
                        fade_in_flag = true;
                        character1.set_x(gil_x);
                        character1.set_y(gil_y);
                        gil_palette.set_fade_intensity(1.0);
                        character1.set_visible(true);
                        sit_memory = 2;
                        ch1_eyes.set_position(-1,-33);
                        ch1_mouth.set_position(0,-18);
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -= 0.01;
                            if(fade_in_intensity<0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            gil_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                        ingram_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                    
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);
               

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::ingram_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::ingram_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            }
            
                break;

            case 66: // ingram silent dana talking
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::ingram);
                    ch1_mouth.set_item(bn::sprite_items::ingram_mouth);
                    ch1_eyes.set_item(bn::sprite_items::ingram_eyes);
                    setup_flag = false;
                    ch1_eyes.set_position(28,-30);
                    ch1_mouth.set_position(33,-11);
                    }
                    
                        if (sit_memory == 64)
                    {
                        character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                        character2.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        anna_tv.set_visible(false);
                        //character1.set_visible(false);
                        fade_in_flag = true;
                        character1.set_x(gil_x);
                        character1.set_y(gil_y);
                        dana_palette.set_fade_intensity(1.0); // making them dark
                        character2.set_visible(true); // turning them back on
                        character1.set_visible(true);
                        sit_memory = 66;
                        fade_in_intensity = 1.0;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -= 0.01;
                            if(fade_in_intensity<0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            dana_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                        ingram_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                    dana_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    character2.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    dana_mouth.set_visible(true);
                    //dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    dana_eyes.set_visible(true);
                    ch1_blink_count++;
                    ch2_blink_count++;

                    
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);

                    if(ch1_anim<=est_time)
                    {
                        if(t<9)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),2);
                    }
                    else if(t<63)
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),1);
                    }
                    // else if(t<72)
                    // {
                    //     dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    // }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    }
                    }
                    else
                    {
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
               

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::ingram_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::ingram_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
                if (ch2_blink_count >= ch2_blink_time && ch2_blink_flag == false) // blinking
                    {
                        dana_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),1);
                        ch2_anim = 0;
                        ch2_blink_count = 0;
                        ch2_blink_flag = true;
                    }
                    if (ch2_blink_flag == true)
                    {
                        ch2_blink_count++;
                        if (ch2_blink_count >= 27)
                        {
                            
                            dana_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                            ch2_anim = 0;
                            ch2_blink_count = 0;
                            ch2_blink_time = random.get_int(180, 600);
                            ch2_blink_flag = false;
                        }
                    }
            }
            
                break;

                case 67: // ingram silent dana silent
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::ingram);
                    ch1_mouth.set_item(bn::sprite_items::ingram_mouth);
                    ch1_eyes.set_item(bn::sprite_items::ingram_eyes);
                    setup_flag = false;
                    ch1_eyes.set_position(28,-30);
                    ch1_mouth.set_position(33,-11);
                    }
                    
                        if (sit_memory == 64)
                    {
                        character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                        character2.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        anna_tv.set_visible(false);
                        //character1.set_visible(false);
                        fade_in_flag = true;
                        character1.set_x(gil_x);
                        character1.set_y(gil_y);
                        dana_palette.set_fade_intensity(1.0); // making them dark
                        character2.set_visible(true); // turning them back on
                        character1.set_visible(true);
                        sit_memory = 66;
                        fade_in_intensity = 1.0;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -= 0.01;
                            if(fade_in_intensity<0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            dana_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                        ingram_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                    dana_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    character2.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    dana_mouth.set_visible(true);
                    //dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    dana_eyes.set_visible(true);
                    ch1_blink_count++;
                    ch2_blink_count++;

                    
                        //ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);

                    
                        dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    
               

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::ingram_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::ingram_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
                if (ch2_blink_count >= ch2_blink_time && ch2_blink_flag == false) // blinking
                    {
                        dana_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),1);
                        ch2_anim = 0;
                        ch2_blink_count = 0;
                        ch2_blink_flag = true;
                    }
                    if (ch2_blink_flag == true)
                    {
                        ch2_blink_count++;
                        if (ch2_blink_count >= 27)
                        {
                            
                            dana_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                            ch2_anim = 0;
                            ch2_blink_count = 0;
                            ch2_blink_time = random.get_int(180, 600);
                            ch2_blink_flag = false;
                        }
                    }
            }
            
                break;

                case 68: // ingram silent dana fading out
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::ingram);
                    ch1_mouth.set_item(bn::sprite_items::ingram_mouth);
                    ch1_eyes.set_item(bn::sprite_items::ingram_eyes);
                    setup_flag = false;
                    ch1_eyes.set_position(28,-30);
                    ch1_mouth.set_position(33,-11);
                    }
                    
                        if (sit_memory == 66)
                    {
                        character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                        character2.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        anna_tv.set_visible(false);
                        //character1.set_visible(false);
                        fade_in_flag = true;
                        character1.set_x(gil_x);
                        character1.set_y(gil_y);
                        dana_eyes.set_visible(false);
                        dana_mouth.set_visible(false);
                        dana_palette.set_fade_intensity(0.0); // making them light
                        character2.set_visible(true); // turning them back on
                        character1.set_visible(true);
                        sit_memory = 68;
                        fade_in_intensity = 0.0;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            fade_in_intensity += 0.01;
                            if(fade_in_intensity > 1.0)
                            {
                                fade_in_intensity = 1.0;
                            }
                            dana_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                        ingram_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                    dana_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                    character1.set_x(gil_x);
                    character1.set_y(gil_y);
                    character1.set_visible(true);
                    character2.set_visible(false);
                    kimsleep_1.set_visible(false);
                    kimsleep_2.set_visible(false);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    dana_mouth.set_visible(false);
                    //dana_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    dana_eyes.set_visible(false);
                    ch1_blink_count++;
                    

                    
                        ch1_mouth.set_tiles(bn::sprite_items::ingram_mouth.tiles_item(),0);

                    
                        
                    
               

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::ingram_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::ingram_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
                
            }
            
                break;

            case 69: // ingram fading out
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::ingram);
                    ch1_mouth.set_item(bn::sprite_items::ingram_mouth);
                    ch1_eyes.set_item(bn::sprite_items::ingram_eyes);
                    setup_flag = false;
                    ch1_eyes.set_position(28,-30);
                    ch1_mouth.set_position(33,-11);
                    }
                    
                        if (sit_memory == 65)
                    {
                        character1.set_map(bn::regular_bg_items::ingram.map_item(), 0);
                        fade_in_flag = true;
                        character1.set_x(gil_x);
                        character1.set_y(gil_y);
                        ch1_eyes.set_visible(false);
                        ch1_mouth.set_visible(false);
                        ingram_palette.set_fade_intensity(0.0); // making them light
                        character1.set_visible(true);
                        sit_memory = 69;
                        fade_in_intensity = 0.0;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            fade_in_intensity += 0.01;
                            if(fade_in_intensity > 1.0)
                            {
                                fade_in_intensity = 1.0;
                            }
                            ingram_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    ingram_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                    character1.set_visible(false);
            }
            
                break;

                    
            
            }
            
                

                t++;

                fan_rot += 3;
                if (fan_rot >= 360)
                {
                    fan_rot = 0;
                }
                bn::fixed fan_angle (fan_rot);
                fan.set_rotation_angle(fan_angle);

                if (line_skip > 2 || frame_skip == true) // skipping some frames between drawing lines
                {
                    
                    if (line_1_ready == false && line_2_ready == false && line_3_ready == false) // setting the next character visible
                    { 
                        max = text_sprites_1.size(); // for this function the value from the vector itself is important. For other applications use TextManager::get_length
                        if (max>0) // checking if the line is empty and should be skipped
                        {
                            if (max > line_1_appear && line_1_ready == false) // setting the next character visible
                            {
                                text_sprites_1[line_1_appear].set_visible(true);
                                if (speech_counter > 0 && frame_skip == false)
                                {
                                    bn::sound_items::speech.play(1.0);
                                    speech_counter = 0;
                                }
                                else
                                {
                                    speech_counter++;
                                }
                                line_1_appear++;
                            }
                            else if (max <= line_1_appear) // checking if this is the last character
                            {
                                line_1_appear--; // IT'S IMPORTANT TO NOT OVERFILL THIS VAR. WHATEVER YOU DO, DO NOT LET IT REACH MAX VALUE!
                                if (line_1_appear < 0 && frame_skip == false)
                                {
                                    line_1_appear = 0;
                                }
                                line_1_ready = true;
                                text_sprites_1[line_1_appear].set_visible(true);
                                line_1.set_one_sprite_per_character(false);
                                line_2.set_one_sprite_per_character(true);
                                line_2_appear = 0;
                            }
                        }
                    }
                    if (line_2_ready == false && line_1_ready == true && line_3_ready == false) // setting the next character visible
                    { 
                        max = text_sprites_2.size(); // for this function the value from the vector itself is important. For other applications use TextManager::get_length
                        if (max > 0) // checking if the line is empty and should be skipped
                        {
                            if (max > line_2_appear && line_2_ready == false) // setting the next character visible
                            {
                                text_sprites_2[line_2_appear].set_visible(true);
                                if (speech_counter > 0 && frame_skip == false)
                                {
                                    bn::sound_items::speech.play(1.0);
                                    speech_counter = 0;
                                }
                                else
                                {
                                    speech_counter++;
                                }
                                line_2_appear++;
                            }
                            else if (max <= line_2_appear) // checking if this is the last character
                            {
                                line_2_appear--; // IT'S IMPORTANT TO NOT OVERFILL THIS VAR. WHATEVER YOU DO, DO NOT LET IT REACH MAX VALUE!
                                if (line_2_appear < 0)
                                {
                                    line_2_appear = 0;
                                }
                                line_2_ready = true;
                                text_sprites_2[line_2_appear].set_visible(true);
                                
                                line_2.set_one_sprite_per_character(false);
                                line_3_appear = 0;
                            }
                            
                        }
                        else // if the line is empty
                        {
                            line_2_ready = true;
                            line_3_appear = 0;
                        }
                    }
                    if (line_3_ready == false && line_1_ready == true && line_2_ready == true) // setting the next character visible
                    { 
                        max = text_sprites_3.size(); // for this function the value from the vector itself is important. For other applications use TextManager::get_length
                        if (max>0) // checking if the line is empty and should be skipped
                        {
                            
                            line_3.set_one_sprite_per_character(true);
                            if (max > line_3_appear && line_3_ready == false) // setting the next character visible
                            {
                                text_sprites_3[line_3_appear].set_visible(true);
                                if (speech_counter > 0 && frame_skip == false)
                                {
                                    bn::sound_items::speech.play(1.0);
                                    speech_counter = 0;
                                }
                                else
                                {
                                    speech_counter++;
                                }
                                line_3_appear++;
                            }
                            else if (max <= line_3_appear) // checking if this is the last character
                            {
                                line_3_appear--; // IT'S IMPORTANT TO NOT OVERFILL THIS VAR. WHATEVER YOU DO, DO NOT LET IT REACH MAX VALUE!
                                if (line_3_appear < 0)
                                {
                                    line_3_appear = 0;
                                }
                                line_3_ready = true;
                                text_sprites_3[line_3_appear].set_visible(true);
                                
                                line_3.set_one_sprite_per_character(false);
                                
                            }
                        }
                        else // if the line is empty
                        {
                            line_3_ready = true;
                        }
                        
                    }
                    
                    
                    

                    line_skip = 0;
                }
                else
                {
                    line_skip++;
                }
                
                if (line_1_ready == true && line_2_ready == true && line_3_ready == true) // Blinking the white triangle upon text completion
                    {
                        if (blink < 36)
                        {
                            textbox.set_map(bn::regular_bg_items::textbox.map_item(), 1);
                            blink++;
                        }
                        else if (blink < 72)
                        {
                            textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0);
                            blink++;
                        }
                        else
                        {
                            blink = 0;
                        }
                        
                    }
                
                    if (a_press_timeout < 5) // updating the a press timer
                    {
                        a_press_timeout++;
                    }


                

                


            
            if(bn::keypad::a_pressed())
            {
                
                if(a_press_timeout > 4)
                {
                    if (line_1_ready == false || line_2_ready == false || line_3_ready == false) // checking if text animation is over
                    {
                        if(frame_skip == false)
                        {
                            frame_skip = true;
                        }
                        else
                        {
                        sit_memory = TextManager::get_situation(current_index/3,1);
                        line_change = true; // triggers the text change
                        current_index += 3; // offsets the line index
                        a_press_timeout = 0; // resets the a press timeout
                        ch1_anim = 0; // resets the talking animation var
                        ch2_anim = 0; // resets the talking animation var
                        line_1_appear = 0;
                        line_2_appear = 0;
                        line_3_appear = 0;
                        line_1_ready = false;
                        line_2_ready = false;
                        line_3_ready = false;
                        fade_in_flag = false;
                        text_sprites_1.clear();
                        textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0); // blinking ends
                        blink = 0;
                        frame_skip = false;
                        anna_tv.set_visible(false);
                        switch(occasion)
                        {
                            case 2:
                                if (current_index == 198)
                                {
                                    current_index == 210;
                                }
                                
                            break;
                        }
                        }
                    }
                    else
                    {
                        
                        sit_memory = TextManager::get_situation(current_index/3,1);
                        line_change = true; // triggers the text change
                        current_index += 3; // offsets the line index
                        a_press_timeout = 0; // resets the a press timeout
                        ch1_anim = 0; // resets the talking animation var
                        ch2_anim = 0;
                        line_1_appear = 0;
                        line_2_appear = 0;
                        line_3_appear = 0;
                        line_1_ready = false;
                        line_2_ready = false;
                        line_3_ready = false;
                        fade_in_flag = false;
                        text_sprites_1.clear();
                        textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0); // blinking ends
                        blink = 0;
                        frame_skip = false;
                        anna_tv.set_visible(false);
                        setup_flag = true;
                        switch(occasion)
                        {
                            case 2:
                                if (current_index == 198)
                                {
                                    current_index == 210;
                                }
                                
                            break;
                        }
                    }
                }
                        

                 
                
            }

            

            //info.update();
            bn::core::update();
        }
        switch(current_situation) // determining what to display next
            {
                case 666: // mixing
                    activity = 2;
                break;
                case 667: // break
                    activity = 3;
                break;
            }
        //bn::core::update();
    }

    void day_1_2()
    {
        int t = 0;
        int occasion = 0;
        int current_index = 0;
        int karmotrine_delta = karmotrine_memory - karmotrine_prev;
        switch(pos)
        {
            case 1:
                if (order > 25 && order < 46) // big drink
                {
                    occasion = 1;
                    current_index = 75;
                }
                else if (order != 5 && order != 6 && order != 18 && order != 21 && order != 20 && order != 16) // normal not sweet
                {
                    occasion = 2;
                    current_index = 84;
                }
                else if (order != 16) // normal not moonblast
                {
                    occasion = 3;
                    current_index = 96;
                }
                else // normal moonblast
                {
                    occasion = 4;
                    current_index = 105;
                }
            break;

            case 2:
                if (order == 1 || order == 6 || order == 7 || order == 10 || order == 15 || order == 26 || order == 31 || order == 32 || order == 35 || order == 39) // classy
                {
                    occasion = 6;
                    current_index = 261;
                }
                else // not classy
                {
                    occasion = 5;
                    current_index = 240;
                }
                if (karmotrine_memory > 6)
                {
                    sei = 1;
                }
                else
                {
                    sei = 0;
                }
            break;

            case 3: // sei third order
                if (order == 6 || order == 31) // branditini
                {
                    occasion = 9;
                    current_index = 513;
                    sei = 0;
                }
                else // not branditini
                {
                    occasion = 8;
                    current_index = 504;
                    if (karmotrine_memory > 6)
                    {
                        sei = 2;
                    }
                    karmotrine_memory = 0;
                    
                }
                
                
            break;

            case 4: // kim first order
                if (order == 17) // piano man
                {
                    kim[1] = 7; // bitter2
                }
                if (order == 33) // big crevice spike
                {
                    kim[1] = 6; // sour2
                }
                if (order == 3 || order == 4 || order == 14 || order == 28 || order == 29) // spicy
                {
                    kim[1] = 5; // bitter
                }
                if (order == 1 || order == 8 || order == 14 || order == 9 || order == 15 || order == 24 || order == 26 || order == 33 || order == 34 || order == 39) // sour
                {
                    kim[1] = 4; // sour
                }
                if (order == 12 || order == 13 || order == 19 || order == 22 || order == 23 || order == 37 || order == 38 || order == 41 || order == 44 || order == 45) // bitter
                {
                    kim[1] = 3; // bitter
                }
                if (order == 5 || order == 6 || order == 16 || order == 18 || order == 20 || order == 21 || order == 30 || order == 31 || order == 42 || order == 43) // sweet
                {
                    kim[1] = 2; // sweet
                }
                if (order == 2 || order == 7 || order == 10 || order == 11 || order == 27 || order == 32 || order == 36 || order == 35) // bubbly
                {
                    kim[1] = 1; // bubbly
                }
                else
                {
                    kim[1] = 0;
                }
                occasion = 10;
                current_index = 708;
            break;

            case 5: // kim second order
                if (order == 17)
                {
                    occasion = 13;
                    current_index = 1005;
                }
                else if (order == 18)
                {
                    occasion = 12;
                    current_index = 972;
                }
                else
                {
                    occasion = 11;
                    current_index = 957;
                }
                
            break;

            case 6: // kim third order
                if (order == 6 || order == 31) // branditini
                {
                    occasion = 16;
                    current_index = 1233;
                }
                else // other
                {
                    occasion = 15;
                    current_index = 1221;
                }
                if (karmotrine_memory > 7)
                    {
                        kim[0] = 1;
                    }
            break;

            
        }
        karmotrine_prev = karmotrine_memory;
        int line_1_index = 0; 
        int line_2_index = 1;
        int line_3_index = 2;
        bool line_change = true; // action flag for changing the text and the situation
        int a_press_timeout = 0; // timeout for the a button

        int ch1_x = 0; //  abg coordinates
        int ch1_y = -10; //  abg coordinates
        int _gil_x = 0; //  temp coord
        int ch1_anim; // counter for the talking animation
        int ch1_blink_time = 180; // stores the current timer for the blinking
        int ch1_blink_count = 0; // counts up till the next blink
        int ch1_blinking = 0; // counts up till the end of blinking
        bool ch1_blink_flag = false;

        int ch2_x = 0; //  abg coordinates
        int ch2_y = -10; //  abg coordinates
        int ch2_anim; // counter for the talking animation
        int ch2_blink_time = 180; // stores the current timer for the blinking
        int ch2_blink_count = 0; // counts up till the next blink
        int ch2_blinking = 0; // counts up till the end of blinking
        bool ch2_blink_flag = false;

        bool fade_in_flag = false; // says if abg is fading in
        bn::fixed fade_in_intensity = 1.0; // starting alpha value
        
        bn::random random;
        int line_1_appear = 0;
        int line_2_appear = 0;
        int line_3_appear = 0;
        bool line_1_ready = false;
        bool line_2_ready = false;
        bool line_3_ready = false;
        int line_1_length = 0;
        int max = 0;
        int line_skip = 0;
        int est_time = 0;
        int sym_sum = 0;
        int blink = 0; // timer for blinking the triangle
        bool frame_skip = false; // frame skipping flag for text generation
        int sit_memory = 0;
        constexpr int tv_x = 24;
        constexpr int tv_y = -61;
        int fan_rot = 0; // rotation var for the fan
        int speech_counter = 0;
        int current_situation = 0;
        //int fade_in_intensity = 0;
        bool setup_flag = true; // a flag for determening the character on the screen
        bool autoclick = false; // a flag for the game to emulate a click

        int anim_timer = 0;
        bool anim_flag = false;
        int x = ch1_x;



        bn::sprite_text_generator line_1(common::variable_8x8_sprite_font);
        bn::sprite_text_generator line_2(common::variable_8x8_sprite_font);
        bn::sprite_text_generator line_3(common::variable_8x8_sprite_font);
 
        line_1.set_left_alignment();
        line_2.set_left_alignment();
        line_3.set_left_alignment();
        line_1.set_bg_priority(1);
        line_2.set_bg_priority(1);
        line_3.set_bg_priority(1);

        bn::vector<bn::sprite_ptr, 64> text_sprites_1;
        bn::vector<bn::sprite_ptr, 64> text_sprites_2;
        bn::vector<bn::sprite_ptr, 64> text_sprites_3;


        bn::string_view line1 = TextManager::get_line(0,day);
        bn::string_view line2 = TextManager::get_line(1,day);
        bn::string_view line3 = TextManager::get_line(2,day);


        // line_1.generate(-112, 48, line1, text_sprites_1);
        // line_2.generate(-112, 60, line2, text_sprites_2);
        // line_3.generate(-112, 72, line3, text_sprites_3);

        bn::vector<bn::sprite_ptr, 20> flanergide_vector;

        //bn::music_items::hopesanddreams.play();
        if(play_flag == false)
        {
            bn::music_items::dusk.play(0.3,true);
            play_flag = true;
        }

        bn::regular_bg_ptr bg_bg = bn::regular_bg_items::bg.create_bg(0, -15);
        bn::regular_bg_ptr textbox = bn::regular_bg_items::textbox.create_bg(8, -48);
        textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0);
        bg_bg.set_priority(3);
        textbox.set_priority(3);
        bn::sprite_ptr fan = bn::sprite_items::fan.create_sprite(tv_x - 50, tv_y - 3);
        fan.set_visible(true);
        fan.set_bg_priority(0);

        bn::regular_bg_ptr character1 = bn::regular_bg_items::gil.create_bg(ch1_x, ch1_y);
        character1.set_priority(1);

        bn::regular_bg_ptr character2 = bn::regular_bg_items::gil.create_bg(ch1_x - 60, ch1_y);
        character2.set_priority(1);
        character2.set_visible(false);
        //gil_abg.set_wrapping_enabled(0);

        bn::sprite_ptr ch1_eyes = bn::sprite_items::gil_eyes.create_sprite(ch1_x - 1, ch1_y - 23);
        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
        ch1_eyes.set_bg_priority(0);
        ch1_eyes.set_visible(false);
        bn::sprite_ptr ch1_mouth = bn::sprite_items::gil_mouth.create_sprite(ch1_x, ch1_y - 8);
        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
        ch1_mouth.set_bg_priority(0);
        ch1_mouth.set_visible(false);
        bn::sprite_ptr ch2_eyes = bn::sprite_items::gil_eyes.create_sprite(ch1_x - 61, ch1_y - 23);
        ch2_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
        ch2_eyes.set_bg_priority(0);
        ch2_eyes.set_visible(false);
        bn::sprite_ptr ch2_mouth = bn::sprite_items::gil_mouth.create_sprite(ch1_x - 60, ch1_y - 8);
        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
        ch2_mouth.set_bg_priority(0);
        ch2_mouth.set_visible(false);

        bn::sprite_ptr sei_helmet = bn::sprite_items::sei_helmet.create_sprite(ch1_x - 59, ch1_y + 1);
        sei_helmet.set_tiles(bn::sprite_items::sei_helmet.tiles_item(),0);
        sei_helmet.set_bg_priority(0);
        sei_helmet.set_visible(false);


        character1.set_item(bn::regular_bg_items::sei);
        bn::bg_palette_ptr sei_palette = character1.palette();
        character1.set_item(bn::regular_bg_items::kim);
        bn::bg_palette_ptr kim_palette = character1.palette();
        character1.set_item(bn::regular_bg_items::dana);
        bn::bg_palette_ptr dana_palette = character1.palette();
        character1.set_item(bn::regular_bg_items::gil);
        bn::bg_palette_ptr gil_palette = character1.palette();

        




        while(current_situation != 666 && current_situation != 667)
        {
            switch(occasion)
            {
                case 1: // Sei order one big
                    if (current_index == 84)
                    {
                        current_index = 111;
                    }
                break;

                case 2: // Sei order one not sweet
                    if (current_index == 96)
                    {
                        current_index = 111;
                    }
                break;

                case 3: // Sei order one sweet not moonblast
                    if (current_index == 105)
                    {
                        current_index = 111;
                    }
                break;

                case 5: // sei second order not classy
                    if (current_index == 261)
                    {
                        current_index = 282;
                    }
                    if (sei != 1 && current_index == 453) 
                    {
                        current_index = 483; 
                        
                    }
                    else if (sei == 1 && current_index == 453)
                    {
                        pos = 3;
                        occasion = 7;
                    }
                    //character1.set_visible(false);
                break;

                case 6: // sei second order classy
                    if (sei != 1 && current_index == 453) 
                    {
                        current_index = 483; 
                        
                    }
                    else if (sei == 1 && current_index == 453)
                    {
                        pos = 3;
                        occasion = 7;
                    }
                break;

                case 7: // sei early drunk
                    if (current_index == 489)
                    {
                        current_index = 627; // CHANGE THE VAR
                    }
                break;

                case 8: // sei third order not branditini
                    if (current_index == 513 && sei == 0)
                    {
                        current_index = 576; // CHANGE THE VAR TO SOBER BEGINNING
                    }
                    if (current_index == 513 && sei == 2) // CHANGE THE VAR TO DRUNK END
                    {
                        current_index = 522; // CHANGE THE VAR TO KIM
                    }
                    if (current_index == 576 && sei == 2)
                    {
                        current_index = 627; // CHANGE THE VAR TO SOBER BEGINNING
                    }
                    
                break;

                case 9: // sei third order branditini
                    if (current_index == 522)
                    {
                        current_index = 576; // CHANGE THE VAR TO SOBER BEGINNING
                    }
                break;

                case 10:
                    if(kim[1] == 5)
                    {
                        if (current_index == 861)
                        {
                            current_index = 867;
                        }
                        else if (current_index == 873)
                        {
                            current_index = 879;
                        }
                    }
                    else if (kim[1] == 2)
                    {
                        if (current_index == 861)
                        {
                            current_index = 873;
                        }
                    }
                    else
                    {
                        if (current_index == 867)
                        {
                            current_index = 879;
                        }
                    }
                break;

                case 11: // kim second order other
                    if (current_index == 972)
                    {
                        current_index = 1044;
                    }
                break;

                case 12: // kim second order piano woman
                    if (current_index == 1005)
                    {
                        current_index = 1044;
                    }
                break;

                case 15: // kim third order other
                    if (kim[0] == 1)
                    {
                        if (current_index == 1233)
                        {
                            current_index = 1242;
                        }
                        if (current_index == 1371)
                        {
                            current_index = 1494;
                        }
                    }
                    else
                    {
                        if (current_index == 1233)
                        {
                            current_index = 1371;
                        }
                    }
                break;

                case 16: // kim third order branditini
                    if (kim[0] == 1)
                    {
                        if (current_index == 1371)
                        {
                            current_index = 1494;
                        }
                    }
                    else
                    {
                        if (current_index == 1239)
                        {
                            current_index = 1371;
                        }
                    }
                break;
            }

            line = current_index + 3;
            line_1_index = current_index;
            line_2_index = current_index + 1;
            line_3_index = current_index + 2;
            if (line_change == true) // generating new text
            {
                text_sprites_1.clear();
                text_sprites_2.clear();
                text_sprites_3.clear();


                bn::string_view line1 = TextManager::get_line(line_1_index,day); // looking up line data
                bn::string_view line2 = TextManager::get_line(line_2_index,day);
                bn::string_view line3 = TextManager::get_line(line_3_index,day);

                

                line_1_length = TextManager::get_length(line_1_index, day);
                //line_1_length -= 5;

                line_1.set_one_sprite_per_character(true); // first line is being drawn
                line_2.set_one_sprite_per_character(true); // the rest are not one sprite per character until it's their turn
                line_3.set_one_sprite_per_character(true);
                line_1.generate(-115, 48, line1, text_sprites_1); // generating a new line
                line_1_appear = 0;
                line_2.generate(-115, 60, line2, text_sprites_2);
                line_3.generate(-115, 72, line3, text_sprites_3);
                line_1.set_visible(false); // making all lines invisible
                line_2.set_visible(false);
                line_3.set_visible(false);


                sym_sum = TextManager::get_length(line_1_index, day) + TextManager::get_length(line_2_index,day) + TextManager::get_length(line_3_index,day);
                est_time = sym_sum/20;
                est_time--;
                if (est_time<=2)
                {
                    est_time = 2;
                }

                
                //char buffer[10];
                
                
                line_change = false;
            }
            
            current_situation = TextManager::get_situation(current_index/3,day);
            switch (current_situation) // Making stuff happen based on the according Situations var
            {
                case 0: // bargroud
                    character1.set_visible(false);
                    ch1_eyes.set_visible(false);
                    ch1_mouth.set_visible(false);
                    character1.set_visible(false);
                    //donovan_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                break;

                case 75: // sei helmet fade in
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-1,-33);
                        ch1_mouth.set_position(0,-18);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::sei.map_item(), 3);
                        setup_flag = false;
                    }
                    if (sit_memory == 0)
                    {
                        sei_palette.set_fade_intensity(1.0);
                        fade_in_intensity = 1.0;
                        character1.set_visible(true);
                        fade_in_flag = true;
                        sit_memory = 75;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -=0.01;
                            if(fade_in_intensity < 0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            sei_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                        
                    }
                    else
                    {
                        sei_palette.set_fade_intensity(0.0);
                    }
                break;
                
                case 76: // sei helmet
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        setup_flag = false;
                        ch1_eyes.set_position(-1,-33);
                        ch1_mouth.set_position(0,-18);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                    }
                    character1.set_map(bn::regular_bg_items::sei.map_item(), 3);
                    sei_palette.set_fade_intensity(0.0); // fixing abg darkening
                break;

                case 77: // sei helmet animation and fading out
                    if (setup_flag == true) // setting up
                    {
                        setup_flag = false;
                        ch1_eyes.set_position(-1,-33);
                        ch1_mouth.set_position(0,-18);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        sei_helmet.set_visible(true);
                        sei_helmet.set_position(8,-24);
                        anim_flag = true;
                    }
                    //character1.set_visible(false);
                    
                    if (anim_flag == true)
                    {
                        switch (anim_timer)
                        {
                            case 0:
                                sei_helmet.set_tiles(bn::sprite_items::sei_helmet.tiles_item(),0);
                            break;

                            case 20:
                                sei_helmet.set_tiles(bn::sprite_items::sei_helmet.tiles_item(),1);
                                character1.set_map(bn::regular_bg_items::sei.map_item(), 4);
                            break;

                            case 26:
                                sei_helmet.set_tiles(bn::sprite_items::sei_helmet.tiles_item(),2);
                            break;

                            case 32:
                                sei_helmet.set_tiles(bn::sprite_items::sei_helmet.tiles_item(),3);
                            break;

                            case 38:
                                sei_helmet.set_tiles(bn::sprite_items::sei_helmet.tiles_item(),4);
                            break;

                            case 44:
                                sei_helmet.set_tiles(bn::sprite_items::sei_helmet.tiles_item(),5);
                            break;

                            case 50:
                                sei_helmet.set_tiles(bn::sprite_items::sei_helmet.tiles_item(),1);
                            break;

                            case 62:
                                anim_flag = false;
                            break;
                        }
                        anim_timer++;
                    }
                    else if (fade_in_flag == false)
                    {
                        sei_helmet.set_visible(false);
                        //sei_palette.set_fade_intensity(0.0);
                        fade_in_intensity = 0.0;
                        character1.set_visible(true);
                        fade_in_flag = true;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            fade_in_intensity +=0.01;
                            if(fade_in_intensity > 1.0)
                            {
                                fade_in_intensity = 1.0;
                            }
                            sei_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            sei_palette.set_fade_intensity(1.0);
                            character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                            fade_in_flag = false;
                            autoclick = true;
                        }
                    }
                break;

                case 78: // sei normal fade in
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(1.0);
                    }
                    if (sit_memory == 0 || sit_memory == 77)
                    {
                        character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        sei_palette.set_fade_intensity(1.0);
                        fade_in_intensity = 1.0;
                        character1.set_visible(true);
                        fade_in_flag = true;
                        sit_memory = 78;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -=0.01;
                            if(fade_in_intensity < 0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            sei_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                        
                    }
                    else
                    {
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        
                        }
                    }
                break;

                case 79: // sei normal silent
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 80: // sei normal talking
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if(ch1_anim<=est_time)
                        {
                            if(t<9)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                            }
                            else if(t<18)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<27)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                            }
                            else if(t<36)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<45)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                            }
                            else if(t<54)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),1);
                            }
                            else if(t<63)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<72)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),1);
                            }
                            else if(t<81)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),3);
                            }
                            else
                            {
                                t=0;
                                ch1_anim++;
                            };
                        }
                        else
                        {
                            ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        }

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 81: // sei worried silent
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),2);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),3);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),2);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 82: // sei worried talking
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),2);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(0.0);
                    }
                        bg_bg.set_position(0, -15);
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if(ch1_anim<=est_time)
                        {
                            if(t<9)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                            }
                            else if(t<18)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<27)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                            }
                            else if(t<36)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<45)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                            }
                            else if(t<54)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),1);
                            }
                            else if(t<63)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<72)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),1);
                            }
                            else if(t<81)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),3);
                            }
                            else
                            {
                                t=0;
                                ch1_anim++;
                            };
                        }
                        else
                        {
                            ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        }

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),3);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),2);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 83: // sei smiling silent
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::sei.map_item(), 1);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 84: // sei smiling talking
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if(ch1_anim<=est_time)
                        {
                            if(t<9)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                            }
                            else if(t<18)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<27)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                            }
                            else if(t<36)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<45)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                            }
                            else if(t<54)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),1);
                            }
                            else if(t<63)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<72)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),1);
                            }
                            else if(t<81)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),3);
                            }
                            else
                            {
                                t=0;
                                ch1_anim++;
                            };
                        }
                        else
                        {
                            ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                        }

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 87: // sei drunk silent
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::sei.map_item(), 2);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),4);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),5);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(0.0);
                    }

                        character1.set_map(bn::regular_bg_items::sei.map_item(), 2);
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),5);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),5);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),4);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 86: // sei drunk talking
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::sei.map_item(), 2);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),4);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),5);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(0.0);
                    }
                        character1.set_map(bn::regular_bg_items::sei.map_item(), 2);
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if(ch1_anim<=est_time)
                        {
                            if(t<9)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),5);
                            }
                            else if(t<18)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),7);
                            }
                            else if(t<27)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),5);
                            }
                            else if(t<36)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),7);
                            }
                            else if(t<45)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),5);
                            }
                            else if(t<54)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),6);
                            }
                            else if(t<63)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),7);
                            }
                            else if(t<72)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),5);
                            }
                            else if(t<81)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),8);
                            }
                            else
                            {
                                t=0;
                                ch1_anim++;
                            };
                        }
                        else
                        {
                            ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),5);
                        }

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),5);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),4);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 85: // sei normal fade out
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(1.0);
                    }
                    if (sit_memory == 0 || sit_memory == 79)
                    {
                        character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        sei_palette.set_fade_intensity(0.0);
                        fade_in_intensity = 0.0;
                        character1.set_visible(true);
                        fade_in_flag = true;
                        ch1_mouth.set_visible(false);
                        ch1_eyes.set_visible(false);
                        sit_memory = 85;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            fade_in_intensity +=0.01;
                            if(fade_in_intensity > 1.0)
                            {
                                fade_in_intensity = 1.0;
                            }
                            sei_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                        
                    }
                    else
                    {
                        character1.set_visible(false);
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(1.0);
                        ch1_mouth.set_visible(false);
                        ch1_eyes.set_visible(false);
                    }
                break;

                case 101: // bargroud shake
                    if (sit_memory == 0)
                    {
                        anim_flag = true;
                        sit_memory = 101;
                    }
                    
                    character1.set_visible(false);
                    ch1_eyes.set_visible(false);
                    ch1_mouth.set_visible(false);
                    if(anim_flag == true)
                    {
                        switch(anim_timer)
                        {
                            case 0:
                                bg_bg.set_position(-3, -17);
                            break;

                            case 5:
                                bg_bg.set_position(0, -12);
                            break;

                            case 10:
                                bg_bg.set_position(2, -15);
                            break;

                            case 15:
                                bg_bg.set_position(-7, -8);
                            break;

                            case 20:
                                bg_bg.set_position(1, -17);
                            break;

                            case 25:
                                bg_bg.set_position(6, -12);
                            break;

                            case 30:
                                bg_bg.set_position(3, -17);
                            break;

                            case 35:
                                bg_bg.set_position(0, -15);
                            break;
                        }
                    anim_timer++;
                    }
                break;

                case 89: // sei normal fade in and out
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(1.0);
                    }
                    if (sit_memory == 0 || sit_memory == 101)
                    {
                        character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        sei_palette.set_fade_intensity(1.0);
                        fade_in_intensity = 1.0;
                        character1.set_visible(true);
                        fade_in_flag = true;
                        sit_memory = 100;
                        ch1_mouth.set_visible(false);
                        ch1_eyes.set_visible(false);
                    }
                    else if (fade_in_flag == true && sit_memory == 100)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -=0.05;
                            if(fade_in_intensity < 0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            sei_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            sit_memory = 89;
                            fade_in_intensity = 0.0;
                            //fade_in_flag = false;
                        }
                        
                    }
                    else if (fade_in_flag == true && sit_memory == 89)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            fade_in_intensity +=0.05;
                            if(fade_in_intensity > 1.0)
                            {
                                fade_in_intensity = 1.0;
                            }
                            sei_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_intensity = 1.0;
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                        fade_in_intensity = 1.0;
                        character1.set_visible(false);
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(false);
                        ch1_eyes.set_visible(false);
                        
                    }
                break;

                case 88: // sei normal fade out
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(1.0);
                    }
                    if (sit_memory == 0 || sit_memory == 87)
                    {
                        character1.set_map(bn::regular_bg_items::sei.map_item(), 2);
                        sei_palette.set_fade_intensity(0.0);
                        fade_in_intensity = 0.0;
                        character1.set_visible(true);
                        fade_in_flag = true;
                        ch1_mouth.set_visible(false);
                        ch1_eyes.set_visible(false);
                        sit_memory = 88;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            fade_in_intensity +=0.01;
                            if(fade_in_intensity > 1.0)
                            {
                                fade_in_intensity = 1.0;
                            }
                            sei_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                        
                    }
                    else
                    {
                        character1.set_visible(false);
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(1.0);
                        ch1_mouth.set_visible(false);
                        ch1_eyes.set_visible(false);
                    }
                break;

                case 90: // sei smiling talking shake
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if(ch1_anim<=est_time)
                        {
                            if(t<9)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                            }
                            else if(t<18)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<27)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                            }
                            else if(t<36)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<45)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                            }
                            else if(t<54)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),1);
                            }
                            else if(t<63)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),2);
                            }
                            else if(t<72)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),1);
                            }
                            else if(t<81)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),3);
                            }
                            else
                            {
                                t=0;
                                ch1_anim++;
                            };
                        }
                        else
                        {
                            ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),4);
                        }

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }

                        if (sit_memory == 84)
                    {
                        anim_flag = true;
                        sit_memory = 90;
                    }
                    
                    if(anim_flag == true)
                    {
                        switch(anim_timer)
                        {
                            case 0:
                                bg_bg.set_position(-3, -17);
                            break;

                            case 5:
                                bg_bg.set_position(0, -12);
                            break;

                            case 10:
                                bg_bg.set_position(2, -15);
                            break;

                            case 15:
                                bg_bg.set_position(-7, -8);
                            break;

                            case 20:
                                bg_bg.set_position(1, -17);
                            break;

                            case 25:
                                bg_bg.set_position(6, -12);
                            break;

                            case 30:
                                bg_bg.set_position(3, -17);
                            break;

                            case 35:
                                bg_bg.set_position(0, -15);
                            break;
                        }
                        anim_timer++;
                    }
                break;

                case 91: // sei worried fade out
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::sei);
                        ch1_mouth.set_item(bn::sprite_items::sei_mouth);
                        ch1_eyes.set_item(bn::sprite_items::sei_eyes);
                        ch1_eyes.set_position(-13,-24);
                        ch1_mouth.set_position(-12,-13);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::sei.map_item(), 1);
                        ch1_eyes.set_tiles(bn::sprite_items::sei_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::sei_mouth.tiles_item(),0);
                        setup_flag = false;
                        sei_palette.set_fade_intensity(1.0);
                    }
                    if (sit_memory == 0 || sit_memory == 81)
                    {
                        character1.set_map(bn::regular_bg_items::sei.map_item(), 1);
                        sei_palette.set_fade_intensity(0.0);
                        fade_in_intensity = 0.0;
                        character1.set_visible(true);
                        fade_in_flag = true;
                        ch1_mouth.set_visible(false);
                        ch1_eyes.set_visible(false);
                        sit_memory = 88;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            fade_in_intensity +=0.01;
                            if(fade_in_intensity > 1.0)
                            {
                                fade_in_intensity = 1.0;
                            }
                            sei_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                        
                    }
                    else
                    {
                        character1.set_visible(false);
                        ch1_eyes.set_position(10,-25);
                        ch1_mouth.set_position(11,-13);
                        sei_palette.set_fade_intensity(1.0);
                        ch1_mouth.set_visible(false);
                        ch1_eyes.set_visible(false);
                    }
                break;


                case 102: // kim normal fade in
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::kim.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(1.0);
                    }
                    if (sit_memory == 0 || sit_memory == 77)
                    {
                        character1.set_map(bn::regular_bg_items::kim.map_item(), 0);
                        kim_palette.set_fade_intensity(1.0);
                        fade_in_intensity = 1.0;
                        character1.set_visible(true);
                        fade_in_flag = true;
                        sit_memory = 78;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -=0.01;
                            if(fade_in_intensity < 0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            kim_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                        
                    }
                    else
                    {
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        
                        }
                    }
                break;

                case 103: // kim normal silent
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(0.0);
                    }
                    
                        character2.set_visible(false);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        kim_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 104: // kim normal talking
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        kim_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if(ch1_anim<=est_time)
                        {
                            if(t<9)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<18)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),1);
                            }
                            else if(t<27)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<36)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),2);
                            }
                            else if(t<45)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<54)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),2);
                            }
                            else if(t<63)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<72)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),3);
                            }
                            else
                            {
                                t=0;
                                ch1_anim++;
                            };
                        }
                        else
                        {
                            ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        }

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 105: // kim angry silent
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),3);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        kim_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),4);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),3);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 106: // kim angry talking
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),3);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        kim_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if(ch1_anim<=est_time)
                        {
                            if(t<9)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<18)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),1);
                            }
                            else if(t<27)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<36)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),2);
                            }
                            else if(t<45)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<56)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),2);
                            }
                            else if(t<63)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<72)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),3);
                            }
                            else
                            {
                                t=0;
                                ch1_anim++;
                            };
                        }
                        else
                        {
                            ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        }

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),4);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),3);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        }
                break;

                case 107: // kim murder
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),5);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(0.0);
                    }
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),5);
                        //ch1_eyes.set_position(-1,-15);
                        //ch1_mouth.set_position(-1,-1);
                        kim_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if(ch1_anim<=est_time)
                        {
                            if(t<3)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                                character1.set_x(ch1_x);
                                character1.set_y(ch1_y);
                                ch1_eyes.set_position(-1,-15);
                                ch1_mouth.set_position(-1,-1);
                            }
                            else if(t<6)
                            {
                                //ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),1);
                                character1.set_x(ch1_x);
                                character1.set_y(ch1_y + 1);
                                ch1_eyes.set_position(-1,-15 + 1);
                                ch1_mouth.set_position(-1,-1 + 1);
                            }
                            else if(t<9)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),2);
                                character1.set_x(ch1_x - 1);
                                character1.set_y(ch1_y);
                                ch1_eyes.set_position(-1 - 1,-15);
                                ch1_mouth.set_position(-1 - 1,-1);
                            }
                            else if(t<12)
                            {
                                //ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),2);
                                character1.set_x(ch1_x + 1);
                                character1.set_y(ch1_y + 1);
                                ch1_eyes.set_position(-1 + 1,-15 + 1);
                                ch1_mouth.set_position(-1 + 1,-1 + 1);
                            }
                            else if(t<15)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),1);
                                character1.set_x(ch1_x);
                                character1.set_y(ch1_y - 1);
                                ch1_eyes.set_position(-1,-15 - 1);
                                ch1_mouth.set_position(-1,-1 - 1);
                            }
                            else if(t<18)
                            {
                                //ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),2);
                                character1.set_x(ch1_x - 1);
                                character1.set_y(ch1_y + 1);
                                ch1_eyes.set_position(-1 - 1,-15 + 1);
                                ch1_mouth.set_position(-1 - 1,-1 + 1);
                            }
                            else if(t<21)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),3);
                                character1.set_x(ch1_x + 1);
                                character1.set_y(ch1_y);
                                ch1_eyes.set_position(-1 + 1,-15);
                                ch1_mouth.set_position(-1 + 1,-1);
                            }
                            else if(t<24)
                            {
                                //ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),3);
                                character1.set_x(ch1_x);
                                character1.set_y(ch1_y + 1);
                                ch1_eyes.set_position(-1,-15 + 1);
                                ch1_mouth.set_position(-1,-1 + 1);
                            }
                            else
                            {
                                t=0;
                                //ch1_anim++;
                            };
                        }
                        else
                        {
                            ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        }

                        
                break;

                case 111: // kim sad silent
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),2);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),4);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        kim_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),4);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        
                break;

                case 110: // kim sad talking
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),2);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),4);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        kim_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        

                        if(ch1_anim<=est_time)
                        {
                            if(t<9)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),4);
                            }
                            else if(t<18)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),5);
                            }
                            else if(t<27)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),4);
                            }
                            else if(t<36)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),6);
                            }
                            else if(t<45)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),4);
                            }
                            else if(t<56)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),6);
                            }
                            else if(t<63)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),4);
                            }
                            else if(t<72)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),7);
                            }
                            else
                            {
                                t=0;
                                ch1_anim++;
                            };
                        }
                        else
                        {
                            ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),4);
                        }

                        
                break;

                case 109: // kim normal sliding right
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(-110);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::kim.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(0.0);
                    }
                        if (sit_memory == 0)
                        {
                            ch1_eyes.set_position(-1,-15);
                            ch1_mouth.set_position(-1,-1);
                            kim_palette.set_fade_intensity(0.0);
                            ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            ch1_mouth.set_visible(false);
                            ch1_eyes.set_visible(false);
                            character1.set_visible(true);
                            fade_in_flag = true;
                            sit_memory = 109;
                            x = -110;
                        }
                        else if (fade_in_flag == true)
                        {
                            x++;
                            if (x > 0)
                            {
                                x = 0;
                                fade_in_flag = false;
                            }
                            character1.set_x(x);
                        }
                        else
                        {
                            character1.set_visible(true);
                            character1.set_x(ch1_x);
                        }
                break;
                

                case 108: // kim normal sliding left
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::kim.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(0.0);
                    }
                if (sit_memory == 103)
                        {
                            ch1_eyes.set_position(-1,-15);
                            ch1_mouth.set_position(-1,-1);
                            kim_palette.set_fade_intensity(0.0);
                            ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            ch1_mouth.set_visible(false);
                            ch1_eyes.set_visible(false);
                            fade_in_flag = true;
                            sit_memory = 108;
                            x = ch1_x;
                            character1.set_blending_enabled(false);
                        }
                        else if (fade_in_flag == true)
                        {
                            x--;
                            if (x < -110)
                            {
                                x = -110;
                                fade_in_flag = false;
                                character1.set_visible(false);
                            }
                            character1.set_x(x);
                        }
                        else
                        {
                            character1.set_visible(false);
                            character1.set_x(ch1_x);
                        }
                break;

                case 11: // normal gil talking
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    ch1_mouth.set_x(ch1_x);
                    ch1_eyes.set_x(ch1_x - 1);
                    }
                    
                        if (sit_memory == 0 || sit_memory == 1 || sit_memory == 108)
                    {
                        character2.set_visible(false);
                        character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                        //anna_tv.set_visible(false);
                        character1.set_visible(false);
                        fade_in_flag = true;
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        gil_palette.set_fade_intensity(1.0);
                        character1.set_visible(true);
                        sit_memory = 11;
                        ch1_mouth.set_x(ch1_x);
                        ch1_eyes.set_x(ch1_x - 1);
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -= 0.01;
                            if(fade_in_intensity<0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            gil_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                    character1.set_x(ch1_x);
                    character1.set_y(ch1_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    
                }

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            
                    break;

                    case 12: // normal gil silent
                    
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }
                    gil_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    fade_in_flag = false; // Preventing a fade in effect
                    character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                    ch1_x = 0;
                    character1.set_x(ch1_x);
                    character1.set_y(ch1_y);
                    ch1_mouth.set_x(ch1_x);
                    ch1_eyes.set_x(ch1_x - 1);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                
                }
                    break;

                case 23: // normal gil fading out
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::gil);
                    ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                    ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                    setup_flag = false;
                    }

                     if (sit_memory == 12)
                    {
                        character1.set_map(bn::regular_bg_items::gil.map_item(), 0);
                        
                        character1.set_visible(false); // making sure they're off
                        ch1_eyes.set_visible(false);
                        ch1_mouth.set_visible(false);

                        fade_in_flag = true;
                        gil_palette.set_fade_intensity(0.0); // making them not dark
                        fade_in_intensity = 0.0;
                        character1.set_visible(true); // turning them back on
                        sit_memory = 23;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            
                            

                            fade_in_intensity += 0.01;
                            if(fade_in_intensity>1.0)
                            {
                                fade_in_intensity = 1.0;
                                
                            }
                            gil_palette.set_fade_intensity(fade_in_intensity);
                           
                            
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    gil_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                    character1.set_visible(false);
                    ch1_eyes.set_visible(false);
                    ch1_mouth.set_visible(false);

                }
                break;

                case 112: // kim sleep
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),1);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(0.0);
                    }
                    
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        kim_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        
                break;

                case 113: // kim sleep talking
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        //character1.set_map(bn::regular_bg_items::sei.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),1);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        setup_flag = false;
                        kim_palette.set_fade_intensity(0.0);
                    }

                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),1);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        kim_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        

                        if(ch1_anim<=est_time)
                        {
                            if(t<9)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<18)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),1);
                            }
                            else if(t<27)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<36)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),2);
                            }
                            else if(t<45)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<56)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),2);
                            }
                            else if(t<63)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                            }
                            else if(t<72)
                            {
                                ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),3);
                            }
                            else
                            {
                                t=0;
                                ch1_anim++;
                            };
                        }
                        else
                        {
                            ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        }

                        
                break;

                case 114: // sleepy kim fading out
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::kim);
                    ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                    ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                    setup_flag = false;
                    }

                     if (sit_memory == 112)
                    {
                        character1.set_map(bn::regular_bg_items::kim.map_item(), 0);
                        
                        character1.set_visible(false); // making sure they're off
                        ch1_eyes.set_visible(false);
                        ch1_mouth.set_visible(false);

                        fade_in_flag = true;
                        kim_palette.set_fade_intensity(0.0); // making them not dark
                        fade_in_intensity = 0.0;
                        character1.set_visible(true); // turning them back on
                        sit_memory = 114;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            
                            

                            fade_in_intensity += 0.01;
                            if(fade_in_intensity>1.0)
                            {
                                fade_in_intensity = 1.0;
                                
                            }
                            kim_palette.set_fade_intensity(fade_in_intensity);
                           
                            
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    kim_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                    character1.set_visible(false);
                    ch1_eyes.set_visible(false);
                    ch1_mouth.set_visible(false);

                }
                break;

                case 24: // gil fucked up fade in
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::gil);
                        ch1_mouth.set_item(bn::sprite_items::gil_mouth);
                        ch1_eyes.set_item(bn::sprite_items::gil_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::gil.map_item(), 3);
                        ch1_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                        ch1_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                        setup_flag = false;
                        gil_palette.set_fade_intensity(1.0);
                    }
                    if (sit_memory == 0)
                    {
                        character1.set_map(bn::regular_bg_items::gil.map_item(), 3);
                        gil_palette.set_fade_intensity(1.0);
                        fade_in_intensity = 1.0;
                        character1.set_visible(true);
                        fade_in_flag = true;
                        sit_memory = 24;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -=0.01;
                            if(fade_in_intensity < 0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            gil_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                        
                    }
                    else
                    {
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        sei_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        
                    }
                break;

                case 120: // kim normal silent gil fucked up fading in
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::kim.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        //setup_flag = false;

                        character2.set_item(bn::regular_bg_items::gil);
                        ch2_mouth.set_item(bn::sprite_items::gil_mouth);
                        ch2_eyes.set_item(bn::sprite_items::gil_eyes);
                        ch2_eyes.set_position(-61,-15);
                        ch2_mouth.set_position(-60,-1);
                        character2.set_x(ch1_x - 60);
                        character2.set_y(ch1_y);
                        character2.set_map(bn::regular_bg_items::gil.map_item(), 3);
                        ch2_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                        setup_flag = false;
                        gil_palette.set_fade_intensity(1.0);
                    }
                    if (sit_memory == 103)
                    {
                        character2.set_map(bn::regular_bg_items::gil.map_item(), 3);
                        gil_palette.set_fade_intensity(1.0);
                        fade_in_intensity = 1.0;
                        character2.set_visible(true);
                        fade_in_flag = true;
                        sit_memory = 24;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -=0.01;
                            if(fade_in_intensity < 0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            gil_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                        
                    }
                    else
                    {
                        character2.set_visible(true);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        gil_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        
                        }
                    }
                break;

                case 121: // kim normal silent gil fucked up talking
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::kim.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        //setup_flag = false;

                        character2.set_item(bn::regular_bg_items::gil);
                        ch2_mouth.set_item(bn::sprite_items::gil_mouth);
                        ch2_eyes.set_item(bn::sprite_items::gil_eyes);
                        ch2_eyes.set_position(-61,-15);
                        ch2_mouth.set_position(-60,-1);
                        character2.set_x(ch1_x - 60);
                        character2.set_y(ch1_y);
                        character2.set_map(bn::regular_bg_items::gil.map_item(), 3);
                        ch2_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                        setup_flag = false;
                        gil_palette.set_fade_intensity(1.0);
                    }
                    
                        character2.set_visible(true);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        gil_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        
                        }
                        
                    
                break;

                case 122: // kim normal silent gil normal talking
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::kim.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        //setup_flag = false;

                        character2.set_item(bn::regular_bg_items::gil);
                        ch2_mouth.set_item(bn::sprite_items::gil_mouth);
                        ch2_eyes.set_item(bn::sprite_items::gil_eyes);
                        ch2_eyes.set_position(-61,-15);
                        ch2_mouth.set_position(-60,-1);
                        character2.set_x(ch1_x - 60);
                        character2.set_y(ch1_y);
                        character2.set_map(bn::regular_bg_items::gil.map_item(), 0);
                        ch2_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                        setup_flag = false;
                        gil_palette.set_fade_intensity(1.0);
                    }
                    
                        character2.set_visible(true);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        gil_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;
                        ch2_blink_count++;

                        if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),2);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                    }

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        
                        }
                        if (ch2_blink_count >= ch2_blink_time && ch2_blink_flag == false) // blinking
                        {
                            ch2_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                            ch2_blinking = 0;
                            ch2_blink_count = 0;
                            ch2_blink_flag = true;
                        }
                        if (ch2_blink_flag == true)
                        {
                            ch2_blink_count++;
                            if (ch2_blink_count >= 27)
                            {
                                
                                ch2_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),0);
                                ch2_blinking = 0;
                                ch2_blink_count = 0;
                                ch2_blink_time = random.get_int(180, 600);
                                ch2_blink_flag = false;
                            }
                        
                        }
                    
                break;

                case 123: // kim normal silent gil fucked up fading out
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::kim);
                        ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                        ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::kim.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::kim_mouth.tiles_item(),0);
                        //setup_flag = false;

                        character2.set_item(bn::regular_bg_items::gil);
                        ch2_mouth.set_item(bn::sprite_items::gil_mouth);
                        ch2_eyes.set_item(bn::sprite_items::gil_eyes);
                        ch2_eyes.set_position(-61,-15);
                        ch2_mouth.set_position(-60,-1);
                        character2.set_x(ch1_x - 60);
                        character2.set_y(ch1_y);
                        character2.set_map(bn::regular_bg_items::gil.map_item(), 3);
                        ch2_eyes.set_tiles(bn::sprite_items::gil_eyes.tiles_item(),1);
                        ch2_mouth.set_tiles(bn::sprite_items::gil_mouth.tiles_item(),0);
                        setup_flag = false;
                        gil_palette.set_fade_intensity(1.0);
                    }
                    if (sit_memory == 122)
                    {
                        character2.set_map(bn::regular_bg_items::gil.map_item(), 3);
                        gil_palette.set_fade_intensity(0.0);
                        fade_in_intensity = 0.0;
                        character2.set_visible(true);
                        fade_in_flag = true;
                        sit_memory = 123;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            fade_in_intensity +=0.01;
                            if(fade_in_intensity > 1.0)
                            {
                                fade_in_intensity = 1.0;
                            }
                            gil_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                        
                    }
                    else
                    {
                        character2.set_visible(false);
                        ch1_eyes.set_position(-1,-15);
                        ch1_mouth.set_position(-1,-1);
                        gil_palette.set_fade_intensity(0.0);
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::kim_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        
                        }
                    }
                break;

                case 115: // normal kim fading out
                    if(setup_flag == true)
                    {
                    character1.set_item(bn::regular_bg_items::kim);
                    ch1_mouth.set_item(bn::sprite_items::kim_mouth);
                    ch1_eyes.set_item(bn::sprite_items::kim_eyes);
                    setup_flag = false;
                    }

                     if (sit_memory == 104)
                    {
                        character1.set_map(bn::regular_bg_items::kim.map_item(), 0);
                        
                        character1.set_visible(false); // making sure they're off
                        ch1_eyes.set_visible(false);
                        ch1_mouth.set_visible(false);

                        fade_in_flag = true;
                        kim_palette.set_fade_intensity(0.0); // making them not dark
                        fade_in_intensity = 0.0;
                        character1.set_visible(true); // turning them back on
                        sit_memory = 115;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity < 1.0)
                        {
                            
                            

                            fade_in_intensity += 0.01;
                            if(fade_in_intensity>1.0)
                            {
                                fade_in_intensity = 1.0;
                                
                            }
                            kim_palette.set_fade_intensity(fade_in_intensity);
                           
                            
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                    }
                    else
                    {
                    kim_palette.set_fade_intensity(1.0); // Fixing a partial abg darkening
                    character1.set_visible(false);
                    ch1_eyes.set_visible(false);
                    ch1_mouth.set_visible(false);

                }
                break;

                case 140: // dana normal fade in
                    if (setup_flag == true) // setting up
                    {
                        character1.set_item(bn::regular_bg_items::dana);
                        ch1_mouth.set_item(bn::sprite_items::dana_mouth);
                        ch1_eyes.set_item(bn::sprite_items::dana_eyes);
                        ch1_eyes.set_position(-2,-22);
                        ch1_mouth.set_position(1,-9);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                        setup_flag = false;
                        dana_palette.set_fade_intensity(1.0);
                    }
                    if (sit_memory == 0 || sit_memory == 77)
                    {
                        ch1_eyes.set_position(-2,-22);
                        ch1_mouth.set_position(1,-9);
                        character1.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        dana_palette.set_fade_intensity(1.0);
                        fade_in_intensity = 1.0;
                        character1.set_visible(true);
                        fade_in_flag = true;
                        sit_memory = 78;
                    }
                    else if (fade_in_flag == true)
                    {
                        if (fade_in_intensity > 0.0)
                        {
                            fade_in_intensity -=0.01;
                            if(fade_in_intensity < 0.0)
                            {
                                fade_in_intensity = 0.0;
                            }
                            dana_palette.set_fade_intensity(fade_in_intensity);
                        }
                        else
                        {
                            fade_in_flag = false;
                        }
                        
                    }
                    else
                    {
                        dana_palette.set_fade_intensity(0.0);
                        ch1_eyes.set_position(-2,-22);
                        ch1_mouth.set_position(1,-9);
                        
                        ch1_mouth.set_visible(true);
                        ch1_eyes.set_visible(true);
                        ch1_blink_count++;

                        if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                        {
                            ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),1);
                            ch1_blinking = 0;
                            ch1_blink_count = 0;
                            ch1_blink_flag = true;
                        }
                        if (ch1_blink_flag == true)
                        {
                            ch1_blink_count++;
                            if (ch1_blink_count >= 27)
                            {
                                
                                ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                                ch1_blinking = 0;
                                ch1_blink_count = 0;
                                ch1_blink_time = random.get_int(180, 600);
                                ch1_blink_flag = false;
                            }
                        
                        }
                    }
                break;

                case 141: // normal dana silent
                    
                    if(setup_flag == true)
                    {
                        character1.set_item(bn::regular_bg_items::dana);
                        ch1_mouth.set_item(bn::sprite_items::dana_mouth);
                        ch1_eyes.set_item(bn::sprite_items::dana_eyes);
                        ch1_eyes.set_position(-2,-22);
                        ch1_mouth.set_position(1,-19);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                        setup_flag = false;
                    }
                    dana_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    fade_in_flag = false; // Preventing a fade in effect
                    character1.set_map(bn::regular_bg_items::dana.map_item(), 0);
                    ch1_x = 0;
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                
                }
                    break;

                case 142: // normal dana talking
                    if(setup_flag == true)
                    {
                        character1.set_item(bn::regular_bg_items::dana);
                        ch1_mouth.set_item(bn::sprite_items::dana_mouth);
                        ch1_eyes.set_item(bn::sprite_items::dana_eyes);
                        ch1_eyes.set_position(-2,-22);
                        ch1_mouth.set_position(1,-9);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                        setup_flag = false;
                    }
                    
                    
                    character1.set_map(bn::regular_bg_items::dana.map_item(), 0);
                    character1.set_x(ch1_x);
                    character1.set_y(ch1_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    //ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),2);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),0);
                    }
                    
                

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            
                    break;

                case 143: // serious dana talking
                    if(setup_flag == true)
                    {
                        character1.set_item(bn::regular_bg_items::dana);
                        ch1_mouth.set_item(bn::sprite_items::dana_mouth);
                        ch1_eyes.set_item(bn::sprite_items::dana_eyes);
                        ch1_eyes.set_position(-2,-22);
                        ch1_mouth.set_position(1,-9);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),3);
                        setup_flag = false;
                    }
                    
                        
                    character1.set_map(bn::regular_bg_items::dana.map_item(), 0);
                    character1.set_x(ch1_x);
                    character1.set_y(ch1_y);
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    //ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),3);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                    if(ch1_anim<=est_time)
                        {
                        if(t<9)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),3);
                    }
                    else if(t<18)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),1);
                    }
                    else if(t<27)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),3);
                    }
                    else if(t<36)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),2);
                    }
                    else if(t<45)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),3);
                    }
                    else if(t<54)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),1);
                    }
                    else if(t<63)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),3);
                    }
                    else if(t<72)
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),2);
                    }
                    else
                    {
                        t=0;
                        ch1_anim++;
                    };
                }
                    else
                    {
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),3);
                    }
                    
                

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                else if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                }
            
                    break;

                case 144: // serious dana silent
                    
                    if(setup_flag == true)
                    {
                        character1.set_item(bn::regular_bg_items::dana);
                        ch1_mouth.set_item(bn::sprite_items::dana_mouth);
                        ch1_eyes.set_item(bn::sprite_items::dana_eyes);
                        ch1_eyes.set_position(-2,-22);
                        ch1_mouth.set_position(1,-9);
                        character1.set_x(ch1_x);
                        character1.set_y(ch1_y);
                        character1.set_map(bn::regular_bg_items::dana.map_item(), 0);
                        ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                        ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),3);
                        setup_flag = false;
                    }
                    dana_palette.set_fade_intensity(0.0); // Fixing a partial abg darkening
                    fade_in_flag = false; // Preventing a fade in effect
                    character1.set_map(bn::regular_bg_items::dana.map_item(), 0);
                    ch1_x = 0;
                    character1.set_visible(true);
                    ch1_mouth.set_visible(true);
                    ch1_mouth.set_tiles(bn::sprite_items::dana_mouth.tiles_item(),3);
                    ch1_eyes.set_visible(true);
                    ch1_blink_count++;

                if (ch1_blink_count >= ch1_blink_time && ch1_blink_flag == false) // blinking
                {
                    ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),1);
                    ch1_blinking = 0;
                    ch1_blink_count = 0;
                    ch1_blink_flag = true;
                }
                if (ch1_blink_flag == true)
                {
                    ch1_blink_count++;
                    if (ch1_blink_count >= 27)
                    {
                        
                        ch1_eyes.set_tiles(bn::sprite_items::dana_eyes.tiles_item(),0);
                        ch1_blinking = 0;
                        ch1_blink_count = 0;
                        ch1_blink_time = random.get_int(180, 600);
                        ch1_blink_flag = false;
                    }
                
                }
                    break;

                

            }

            t++;

            fan_rot += 3;
                if (fan_rot >= 360)
                {
                    fan_rot = 0;
                }
                bn::fixed fan_angle (fan_rot);
                fan.set_rotation_angle(fan_angle);

            if (line_skip > 2 || frame_skip == true) // skipping some frames between drawing lines
                {
                    
                    if (line_1_ready == false && line_2_ready == false && line_3_ready == false) // setting the next character visible
                    { 
                        max = text_sprites_1.size(); // for this function the value from the vector itself is important. For other applications use TextManager::get_length
                        if (max>0) // checking if the line is empty and should be skipped
                        {
                            if (max > line_1_appear && line_1_ready == false) // setting the next character visible
                            {
                                text_sprites_1[line_1_appear].set_visible(true);
                                if (speech_counter > 0 && frame_skip == false)
                                {
                                    bn::sound_items::speech.play(1.0);
                                    speech_counter = 0;
                                }
                                else
                                {
                                    speech_counter++;
                                }
                                line_1_appear++;
                            }
                            else if (max <= line_1_appear) // checking if this is the last character
                            {
                                line_1_appear--; // IT'S IMPORTANT TO NOT OVERFILL THIS VAR. WHATEVER YOU DO, DO NOT LET IT REACH MAX VALUE!
                                if (line_1_appear < 0 && frame_skip == false)
                                {
                                    line_1_appear = 0;
                                }
                                line_1_ready = true;
                                text_sprites_1[line_1_appear].set_visible(true);
                                line_1.set_one_sprite_per_character(false);
                                line_2.set_one_sprite_per_character(true);
                                line_2_appear = 0;
                            }
                        }
                    }
                    if (line_2_ready == false && line_1_ready == true && line_3_ready == false) // setting the next character visible
                    { 
                        max = text_sprites_2.size(); // for this function the value from the vector itself is important. For other applications use TextManager::get_length
                        if (max > 0) // checking if the line is empty and should be skipped
                        {
                            if (max > line_2_appear && line_2_ready == false) // setting the next character visible
                            {
                                text_sprites_2[line_2_appear].set_visible(true);
                                if (speech_counter > 0 && frame_skip == false)
                                {
                                    bn::sound_items::speech.play(1.0);
                                    speech_counter = 0;
                                }
                                else
                                {
                                    speech_counter++;
                                }
                                line_2_appear++;
                            }
                            else if (max <= line_2_appear) // checking if this is the last character
                            {
                                line_2_appear--; // IT'S IMPORTANT TO NOT OVERFILL THIS VAR. WHATEVER YOU DO, DO NOT LET IT REACH MAX VALUE!
                                if (line_2_appear < 0)
                                {
                                    line_2_appear = 0;
                                }
                                line_2_ready = true;
                                text_sprites_2[line_2_appear].set_visible(true);
                                
                                line_2.set_one_sprite_per_character(false);
                                line_3_appear = 0;
                            }
                            
                        }
                        else // if the line is empty
                        {
                            line_2_ready = true;
                            line_3_appear = 0;
                        }
                    }
                    if (line_3_ready == false && line_1_ready == true && line_2_ready == true) // setting the next character visible
                    { 
                        max = text_sprites_3.size(); // for this function the value from the vector itself is important. For other applications use TextManager::get_length
                        if (max>0) // checking if the line is empty and should be skipped
                        {
                            
                            line_3.set_one_sprite_per_character(true);
                            if (max > line_3_appear && line_3_ready == false) // setting the next character visible
                            {
                                text_sprites_3[line_3_appear].set_visible(true);
                                if (speech_counter > 0 && frame_skip == false)
                                {
                                    bn::sound_items::speech.play(1.0);
                                    speech_counter = 0;
                                }
                                else
                                {
                                    speech_counter++;
                                }
                                line_3_appear++;
                            }
                            else if (max <= line_3_appear) // checking if this is the last character
                            {
                                line_3_appear--; // IT'S IMPORTANT TO NOT OVERFILL THIS VAR. WHATEVER YOU DO, DO NOT LET IT REACH MAX VALUE!
                                if (line_3_appear < 0)
                                {
                                    line_3_appear = 0;
                                }
                                line_3_ready = true;
                                text_sprites_3[line_3_appear].set_visible(true);
                                
                                line_3.set_one_sprite_per_character(false);
                                
                            }
                        }
                        else // if the line is empty
                        {
                            line_3_ready = true;
                        }
                        
                    }
                    
                    
                    

                    line_skip = 0;
                }
                else
                {
                    line_skip++;
                }
                
                if (line_1_ready == true && line_2_ready == true && line_3_ready == true) // Blinking the white triangle upon text completion
                    {
                        if (blink < 36)
                        {
                            textbox.set_map(bn::regular_bg_items::textbox.map_item(), 1);
                            blink++;
                        }
                        else if (blink < 72)
                        {
                            textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0);
                            blink++;
                        }
                        else
                        {
                            blink = 0;
                        }
                        
                    }
                
                    if (a_press_timeout < 5) // updating the a press timer
                    {
                        a_press_timeout++;
                    }
            

            if(bn::keypad::a_pressed() || autoclick == true)
            {
                
                if(a_press_timeout > 4)
                {
                    if (line_1_ready == false || line_2_ready == false || line_3_ready == false) // checking if text animation is over
                    {
                        if(frame_skip == false)
                        {
                            frame_skip = true;
                        }
                        else
                        {
                        sit_memory = TextManager::get_situation(current_index/3, day);
                        line_change = true; // triggers the text change
                        current_index += 3; // offsets the line index
                        a_press_timeout = 0; // resets the a press timeout
                        ch1_anim = 0; // resets the talking animation var
                        ch2_anim = 0; // resets the talking animation var
                        line_1_appear = 0;
                        line_2_appear = 0;
                        line_3_appear = 0;
                        line_1_ready = false;
                        line_2_ready = false;
                        line_3_ready = false;
                        fade_in_flag = false;
                        text_sprites_1.clear();
                        textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0); // blinking ends
                        blink = 0;
                        frame_skip = false;
                        //anna_tv.set_visible(false);
                        autoclick = false;
                        }
                    }
                    else
                    {
                        
                        sit_memory = TextManager::get_situation(current_index/3, day);
                        line_change = true; // triggers the text change
                        current_index += 3; // offsets the line index
                        a_press_timeout = 0; // resets the a press timeout
                        ch1_anim = 0; // resets the talking animation var
                        ch2_anim = 0;
                        line_1_appear = 0;
                        line_2_appear = 0;
                        line_3_appear = 0;
                        line_1_ready = false;
                        line_2_ready = false;
                        line_3_ready = false;
                        fade_in_flag = false;
                        text_sprites_1.clear();
                        textbox.set_map(bn::regular_bg_items::textbox.map_item(), 0); // blinking ends
                        blink = 0;
                        frame_skip = false;
                        //anna_tv.set_visible(false);
                        setup_flag = true;
                        autoclick = false;
                        bg_bg.set_position(0, -15);
                    }
                }
                        

                 
                
            }

            

            //info.update();
            bn::core::update();
            }
             switch(current_situation) // determining what to display next
            {
                case 666: // mixing
                    activity = 2;
                break;
                case 667: // break
                    activity = 3;
                break;
            }
            
            }
    

    void mixing()
    {
        karmotrine_prev = karmotrine_memory;
        constexpr const int first_row = -17;
        constexpr const int other_rows = -24;
        constexpr const int second_row = 34;
        constexpr const int other_second_rows = 36;
        constexpr const int first_col = -95;
        constexpr const int second_col = -65;
        constexpr const int third_col = 2;
        constexpr const int fourth_col = 71;

          int sugar_rush[] = {0,0,2,0,0,1,21};
          //bn::array<0,0> = {0,0};


        int amount_x = 1; // coordinate for the amount sprite batch draw
        int pickup_timer = 0; // a timer for the ingredient anim
        int cursor_x = second_col; // cursor x coordinate
        int cursor_y = other_rows; // cursor y coordinate
        int a_timeout = 0; // a button press timeout
        int ingredient = 0; // a flag for adding an ingredient. 0 is off, 1 - ice, 2 - age, 3 - adelhyde, 4 - flanergide, 5 - bronson, 6 - delta, 7 - karmotrine
        int flanergide_amount = 0;
        int adelhyde_amount = 0;
        int bronson_amount = 0;
        int delta_amount = 0;
        int karmotrine_amount = 0;
        int ice_flag = 0;
        int age_flag = 0;
        int blend_flag = 0;
        int total_amount = 0;
        bool mixing_flag = false;
        bool mixing_mem = false;
        bool mixing_limit = false;
        int mixing_timer = 0;
        int mixing_speed = 4;
        bool drink_ready = false;
        bool pulse_flag = false;
        int pulse_timer = 0;
        bool ready_flag = false;
        bool memory_flag = false;
        int result = 0;
        int karmotrine_mem = 0;
        int success_y = 0;
        bool success_flag = false;
        bool fail_flag = false;
        bool reset_allowed = false;
        bool pass_flag = false;


        bn::regular_bg_ptr frame = bn::regular_bg_items::frame.create_bg(0, 0);
        bn::regular_bg_ptr textbox = bn::regular_bg_items::textbox.create_bg(8, -48);
        frame.set_priority(3);
        textbox.set_priority(1);
        textbox.set_visible(false);

        int line_1_index = line;
        int line_2_index = line + 1;
        int line_3_index = line + 2;

        
        bn::sprite_text_generator line_1(common::variable_8x8_sprite_font);
        bn::sprite_text_generator line_2(common::variable_8x8_sprite_font);
        bn::sprite_text_generator line_3(common::variable_8x8_sprite_font);
 
        line_1.set_left_alignment();
        line_2.set_left_alignment();
        line_3.set_left_alignment();
        line_1.set_bg_priority(0);
        line_2.set_bg_priority(0);
        line_3.set_bg_priority(0);
        line_1.set_one_sprite_per_character(false);
        line_2.set_one_sprite_per_character(false);
        line_3.set_one_sprite_per_character(false);


        bn::vector<bn::sprite_ptr, 64> text_sprites;

        bn::string_view line1 = TextManager::get_line(line_1_index,day);
        bn::string_view line2 = TextManager::get_line(line_2_index,day);
        bn::string_view line3 = TextManager::get_line(line_3_index,day);


        line_1.generate(-112, 48, line1, text_sprites);
        line_2.generate(-112, 60, line2, text_sprites);
        line_3.generate(-112, 72, line3, text_sprites);
        for(int c = 0; c < text_sprites.size(); ++c)
        {
            text_sprites[c].set_visible(false);
        }
        


        bn::sprite_ptr slot_1 = bn::sprite_items::slot.create_sprite(64, -68);
        bn::sprite_ptr slot_2 = bn::sprite_items::slot.create_sprite(100, -68);
        bn::sprite_ptr delta = bn::sprite_items::delta.create_sprite(64, -31);
        bn::sprite_ptr karmotrine = bn::sprite_items::karmotrine.create_sprite(64, 21);
        bn::sprite_ptr bronson = bn::sprite_items::bronson.create_sprite(-4, -31);
        bn::sprite_ptr adelhyde = bn::sprite_items::adelhyde.create_sprite(-72, -31);
        bn::sprite_ptr flanergide = bn::sprite_items::flanergide.create_sprite(-72, 21);
        bn::sprite_ptr ice = bn::sprite_items::ice.create_sprite(-102, -32);
        bn::sprite_ptr age = bn::sprite_items::age.create_sprite(-102, 19);
        bn::sprite_ptr shaker = bn::sprite_items::shaker.create_sprite(17, 28);
        bn::sprite_ptr cursor = bn::sprite_items::cursor.create_sprite(second_col, other_rows);
        bn::sprite_ptr shaker_pulse = bn::sprite_items::shaker_pulse.create_sprite(17, 28);
        //bn::sprite_palette_ptr pulse_1 = bn::sprite_palette_items::pulse_palette_1.create_palette();
        //bn::sprite_palette_ptr pulse_2 = bn::sprite_palette_items::pulse_palette_2.create_palette();
        //bn::sprite_palette_ptr pulse_3 = bn::sprite_palette_items::pulse_palette_3.create_palette();
        //bn::sprite_palette_ptr pulse_4 = bn::sprite_palette_items::pulse_palette_4.create_palette();
        //bn::sprite_palette_ptr pulse_5 = bn::sprite_palette_items::pulse_palette_5.create_palette();

        slot_1.set_tiles(bn::sprite_items::slot.tiles_item(), 0);
        slot_2.set_tiles(bn::sprite_items::slot.tiles_item(), 13);
        ice.set_tiles(bn::sprite_items::ice.tiles_item(), 1);
        age.set_tiles(bn::sprite_items::age.tiles_item(), 1);

        delta.set_bg_priority(1);
        karmotrine.set_bg_priority(1);
        bronson.set_bg_priority(1);
        adelhyde.set_bg_priority(1);
        flanergide.set_bg_priority(1);
        shaker.set_bg_priority(2);
        cursor.set_bg_priority(1);

        shaker_pulse.set_visible(false);

        

        bn::vector<bn::sprite_ptr, 64> drink_name_vector;
        bn::sprite_text_generator drink_name(common::variable_8x8_sprite_font);


        bn::sprite_ptr drink = bn::sprite_items::glitchbottle.create_sprite(17, 28);
        drink.set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::bad_touch.create_sprite(17, 28));
        // drinks_vector[1].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::beer.create_sprite(17, 28));
        // drinks_vector[2].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::bleeding_jane.create_sprite(17, 28));
        // drinks_vector[3].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::bloom_light.create_sprite(17, 28));
        // drinks_vector[4].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::blue_fairy.create_sprite(17, 28));
        // drinks_vector[5].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::branditini.create_sprite(17, 28));
        // drinks_vector[6].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::cobalt_velvet.create_sprite(17, 28));
        // drinks_vector[7].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::crevice_spike.create_sprite(17, 28));
        // drinks_vector[8].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::fluffy_dream.create_sprite(17, 28));
        // drinks_vector[9].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::fringe_weaver.create_sprite(17, 28));
        // drinks_vector[10].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::beer.create_sprite(17, 28));
        // drinks_vector[11].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::grizzly_temple.create_sprite(17, 28));
        // drinks_vector[12].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::gut_punch.create_sprite(17, 28));
        // drinks_vector[13].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::marsblast.create_sprite(17, 28));
        // drinks_vector[14].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::mercury_blast.create_sprite(17, 28));
        // drinks_vector[15].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::moonblast.create_sprite(17, 28));
        // drinks_vector[16].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::piano_man.create_sprite(17, 28));
        // drinks_vector[17].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::piano_woman.create_sprite(17, 28));
        // drinks_vector[18].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::piledriver.create_sprite(17, 28));
        // drinks_vector[19].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::sparkle_star.create_sprite(17, 28));
        // drinks_vector[20].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::sugar_rush.create_sprite(17, 28));
        // drinks_vector[21].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::sunshine_cloud.create_sprite(17, 28));
        // drinks_vector[22].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::suplex.create_sprite(17, 28));
        // drinks_vector[23].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::zen_star.create_sprite(17, 28));
        // drinks_vector[24].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::flaming_moai.create_sprite(17, 28));
        // drinks_vector[25].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::absynthe.create_sprite(17, 28));
        // drinks_vector[26].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::fedora.create_sprite(17, 28));
        // drinks_vector[27].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::rum.create_sprite(17, 28));
        // drinks_vector[28].set_visible(false);
        // drinks_vector.push_back(bn::sprite_items::tea.create_sprite(17, 28));
        // drinks_vector[29].set_visible(false);
        
        // for (int i = 0; i < 30; i++)
        // {
        //     drinks_vector[i].set_visible(false);
        //     drinks_vector[i].set_bg_priority(1);
        // }
        
        
        
                    
        

        bn::vector<bn::sprite_ptr, 10> flanergide_vector;
        bn::vector<bn::sprite_ptr, 10> adelhyde_vector;
        bn::vector<bn::sprite_ptr, 10> bronson_vector;
        bn::vector<bn::sprite_ptr, 10> delta_vector;
        bn::vector<bn::sprite_ptr, 10> karmotrine_vector;

        bn::vector<bn::sprite_ptr, 10> shaker_bar_vector;

        shaker.set_rotation_angle(180);

        bn::sprite_ptr success_spr = bn::sprite_items::success.create_sprite(17, 28);
        success_spr.set_visible(false);


        for (int c = 0; c < 5; ++c) // creating sprites for the shaker bar
        {
            shaker_bar_vector.push_back(bn::sprite_items::shaker_bar.create_sprite(amount_x, 65));
            amount_x += 8;
        }
        amount_x = 1;
        for (int c = 0; c < 5; ++c) // creating sprites for the shaker bar
        {
            shaker_bar_vector.push_back(bn::sprite_items::shaker_bar.create_sprite(amount_x, 70));
            amount_x += 8;
        }
        amount_x = -56;

        for (int c = 0; c < 5; ++c) // creating sprites for the first row of flanergide
        {
            flanergide_vector.push_back(bn::sprite_items::amount.create_sprite(amount_x, 10));
            amount_x += 8;
        }
        amount_x = -56;
        for (int c = 0; c < 5; ++c) // creating sprites for the second row of flanergide
        {
            flanergide_vector.push_back(bn::sprite_items::amount.create_sprite(amount_x, 28));
            amount_x += 8;
        }
        amount_x = -56;
        for (int c = 0; c < 5; ++c) // creating sprites for the first row of adelhyde
        {
            adelhyde_vector.push_back(bn::sprite_items::amount.create_sprite(amount_x, -42));
            amount_x += 8;
        }
        amount_x = -56;
        for (int c = 0; c < 5; ++c) // creating sprites for the second row of adelhyde
        {
            adelhyde_vector.push_back(bn::sprite_items::amount.create_sprite(amount_x, -24));
            amount_x += 8;
        }
        amount_x = 12;
        for (int c = 0; c < 5; ++c) // creating sprites for the first row of bronson
        {
            bronson_vector.push_back(bn::sprite_items::amount.create_sprite(amount_x, -42));
            amount_x += 8;
        }
        amount_x = 12;
        for (int c = 0; c < 5; ++c) // creating sprites for the second row of bronson
        {
            bronson_vector.push_back(bn::sprite_items::amount.create_sprite(amount_x, -24));
            amount_x += 8;
        }
        amount_x = 80;
        for (int c = 0; c < 5; ++c) // creating sprites for the first row of delta
        {
            delta_vector.push_back(bn::sprite_items::amount.create_sprite(amount_x, -42));
            amount_x += 8;
        }
        amount_x = 80;
        for (int c = 0; c < 5; ++c) // creating sprites for the second row of delta
        {
            delta_vector.push_back(bn::sprite_items::amount.create_sprite(amount_x, -24));
            amount_x += 8;
        }
        amount_x = 80;
        for (int c = 0; c < 5; ++c) // creating sprites for the first row of karmotrine
        {
            karmotrine_vector.push_back(bn::sprite_items::amount.create_sprite(amount_x, 10));
            amount_x += 8;
        }
        amount_x = 80;
        for (int c = 0; c < 5; ++c) // creating sprites for the second row of karmotrine
        {
            karmotrine_vector.push_back(bn::sprite_items::amount.create_sprite(amount_x, 28));
            amount_x += 8;
        }
        
        for (int c = 0; c < 10; ++c) // Changing the amount tiles to the defaults
        {
            flanergide_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 0);
            adelhyde_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 3);
            bronson_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 6);
            delta_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 9);
            karmotrine_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 12);

            shaker_bar_vector[c].set_visible(false); // turning off the shaker bar sprites
        }
        
        



        while(pass_flag == false)
        {

            switch (ingredient)
            {

                case 1: // ice
                    if (ice_flag == 0)
                    {
                        ice.set_tiles(bn::sprite_items::ice.tiles_item(), 0);
                        bn::sound_items::ice_choose.play(1.0);
                        ice_flag = 1;
                        ingredient = 0;
                    }
                    else
                    {
                        ice.set_tiles(bn::sprite_items::ice.tiles_item(), 1);
                        bn::sound_items::decline.play(1.0);
                        ice_flag = 0;
                        ingredient = 0;
                    }
                break;

                case 2: // age
                    if (age_flag == 0)
                    {
                        age.set_tiles(bn::sprite_items::age.tiles_item(), 0);
                        bn::sound_items::age_choose.play(1.0);
                        age_flag = 1;
                        ingredient = 0;
                    }
                    else
                    {
                        age.set_tiles(bn::sprite_items::age.tiles_item(), 1);
                        bn::sound_items::decline.play(1.0);
                        age_flag = 0;
                        ingredient = 0;
                    }
                break;
                
                case 3: // add adelhyde
                    if(total_amount < 20) // only adding if the shaker is not full
                    {
                        if(pickup_timer < 2) // adelhyde animation
                        {
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 2);
                        }
                        else if(pickup_timer < 4)
                        {
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 3);
                            adelhyde.set_tiles(bn::sprite_items::adelhyde.tiles_item(), 1);
                            adelhyde.set_position(-70, -29);
                        }
                        else if(pickup_timer < 6)
                        {
                            cursor.set_position(-45, -17);
                            adelhyde.set_position(- 50, -24);
                        }
                        else if(pickup_timer < 9)
                        {
                            cursor.set_position(-25, -12);
                            adelhyde.set_position(- 30, -19);
                        }
                        else if(pickup_timer < 11)
                        {
                            cursor.set_position(-5, 5);
                            adelhyde.set_position(- 10, -2);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 1);
                        }
                        else if(pickup_timer < 13)
                        {
                            cursor.set_position(25, 20);
                            adelhyde.set_position(20, 13);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 1);
                        }
                        else if(pickup_timer > 15)
                        {
                            cursor.set_position(-65, -16);
                            adelhyde.set_position(-72, -31);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 0);
                            adelhyde.set_tiles(bn::sprite_items::adelhyde.tiles_item(), 0);
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 2);
                            pickup_timer = -1;
                            ingredient = 0;
                            a_timeout = 50;
                            adelhyde_amount++;
                            shaker_pulse.set_tiles(bn::sprite_items::shaker_pulse.tiles_item(), 1);
                            shaker_pulse.set_visible(true);
                            pulse_flag = true;
                            bn::sound_items::pour.play(1.0);
                        }
                        pickup_timer++;
                    }
                    
                break;

                case 4: // add flanergide
                    if(total_amount < 20) // only adding if the shaker is not full
                    {
                        if(pickup_timer < 2) // flanergide animation
                        {
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 2);
                        }
                        else if(pickup_timer < 4)
                        {
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 3);
                            flanergide.set_tiles(bn::sprite_items::flanergide.tiles_item(), 1);
                            flanergide.set_position(-70, 23);
                        }
                        else if(pickup_timer < 6)
                        {
                            cursor.set_position(second_col + 24 + 7, other_second_rows + 2 + 15);
                            flanergide.set_position(second_col + 24, other_second_rows);
                        }
                        else if(pickup_timer < 9)
                        {
                            cursor.set_position(second_col + 45 + 7, other_second_rows + 2 + 15);
                            flanergide.set_position(second_col + 45, other_second_rows);
                        }
                        else if(pickup_timer < 11)
                        {
                            cursor.set_position(second_col + 65 + 7, other_second_rows + 2 + 15);
                            flanergide.set_position(second_col + 65, other_second_rows);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 1);
                        }
                        else if(pickup_timer < 13)
                        {
                            cursor.set_position(second_col + 80 + 7, other_second_rows + 2 + 15);
                            flanergide.set_position(second_col + 80, other_second_rows);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 1);
                        }
                        else if(pickup_timer > 15)
                        {
                            cursor.set_position(second_col, other_second_rows);
                            flanergide.set_position(-72, 21);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 0);
                            flanergide.set_tiles(bn::sprite_items::flanergide.tiles_item(), 0);
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 2);
                            pickup_timer = -1;
                            ingredient = 0;
                            a_timeout = 50;
                            flanergide_amount++;
                            shaker_pulse.set_tiles(bn::sprite_items::shaker_pulse.tiles_item(), 4);
                            shaker_pulse.set_visible(true);
                            pulse_flag = true;
                            bn::sound_items::pour.play(1.0);
                        }
                        pickup_timer++;
                    }
                    
                break;

                case 5: // add bronson
                    if(total_amount < 20) // only adding if the shaker is not full
                    {
                        if(pickup_timer < 2) // bronson animation
                        {
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 2);
                        }
                        else if(pickup_timer < 5)
                        {
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 3);
                            bronson.set_tiles(bn::sprite_items::bronson.tiles_item(), 1);
                            bronson.set_position(-2, -29);
                        }
                        else if(pickup_timer < 7)
                        {
                            cursor.set_position(third_col + 7, other_rows + 15 + 12);
                            bronson.set_position(third_col, other_rows + 12);
                        }
                        else if(pickup_timer < 9)
                        {
                            cursor.set_position(third_col + 7 + 7, other_rows + 15 + 25);
                            bronson.set_position(third_col + 7, other_rows + 25);
                        }
                        else if(pickup_timer < 12)
                        {
                            cursor.set_position(third_col + 7 + 15, other_rows + 15 + 44);
                            bronson.set_position(third_col + 15, other_rows + 44);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 1);
                        }
                        else if(pickup_timer > 15)
                        {
                            cursor.set_position(third_col, other_rows);
                            bronson.set_position(-4, -31);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 0);
                            bronson.set_tiles(bn::sprite_items::bronson.tiles_item(), 0);
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 2);
                            pickup_timer = -1;
                            ingredient = 0;
                            a_timeout = 50;
                            bronson_amount++;
                            shaker_pulse.set_tiles(bn::sprite_items::shaker_pulse.tiles_item(), 5);
                            shaker_pulse.set_visible(true);
                            pulse_flag = true;
                            bn::sound_items::pour.play(1.0);
                        }
                        pickup_timer++;
                    }
                    
                break;

                case 6: // add delta
                if(total_amount < 20) // only adding if the shaker is not full
                {
                    if(pickup_timer < 2) // delta animation
                        {
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 2);
                        }
                        else if(pickup_timer < 4)
                        {
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 3);
                            delta.set_tiles(bn::sprite_items::delta.tiles_item(), 1);
                            delta.set_position(66, -29);
                        }
                        else if(pickup_timer < 6)
                        {
                            cursor.set_position(58, -12);
                            delta.set_position(51, -19);
                        }
                        else if(pickup_timer < 9)
                        {
                            cursor.set_position(48, -7);
                            delta.set_position(41, -12);
                        }
                        else if(pickup_timer < 11)
                        {
                            cursor.set_position(38, 10);
                            delta.set_position(31, 3);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 1);
                        }
                        else if(pickup_timer < 13)
                        {
                            cursor.set_position(25, 20);
                            delta.set_position(20, 13);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 1);
                        }
                        else if(pickup_timer > 15)
                        {
                            cursor.set_position(fourth_col, other_rows);
                            delta.set_position(64, -31);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 0);
                            delta.set_tiles(bn::sprite_items::delta.tiles_item(), 0);
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 2);
                            pickup_timer = -1;
                            ingredient = 0;
                            a_timeout = 50;
                            delta_amount++;
                            shaker_pulse.set_tiles(bn::sprite_items::shaker_pulse.tiles_item(), 0);
                            shaker_pulse.set_visible(true);
                            pulse_flag = true;
                            bn::sound_items::pour.play(1.0);
                        }
                        pickup_timer++;
                }
                    
                break;

                case 7: // add karmotrine
                    if(total_amount < 20) // only adding if the shaker is not full
                    {
                        if(pickup_timer < 2) // karmotrine animation
                        {
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 2);
                        }
                        else if(pickup_timer < 4)
                        {
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 3);
                            karmotrine.set_tiles(bn::sprite_items::karmotrine.tiles_item(), 1);
                            karmotrine.set_position(66, 23);
                        }
                        else if(pickup_timer < 6)
                        {
                            cursor.set_position(fourth_col - 12 + 7, other_second_rows + 2);
                            karmotrine.set_position(fourth_col - 12, other_second_rows - 13);
                        }
                        else if(pickup_timer < 9)
                        {
                            cursor.set_position(fourth_col - 20 + 7, other_second_rows + 2);
                            karmotrine.set_position(fourth_col - 20, other_second_rows - 13);
                        }
                        else if(pickup_timer < 11)
                        {
                            cursor.set_position(fourth_col - 35 + 7, other_second_rows + 2);
                            karmotrine.set_position(fourth_col - 35, other_second_rows - 13);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 1);
                        }
                        else if(pickup_timer < 13)
                        {
                            cursor.set_position(fourth_col - 50 + 7, other_second_rows + 2);
                            karmotrine.set_position(fourth_col - 50, other_second_rows - 13);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 1);
                        }
                        else if(pickup_timer > 15)
                        {
                            cursor.set_position(fourth_col, other_second_rows);
                            karmotrine.set_position(64, 21);
                            shaker.set_tiles(bn::sprite_items::shaker.tiles_item(), 0);
                            karmotrine.set_tiles(bn::sprite_items::karmotrine.tiles_item(), 0);
                            cursor.set_tiles(bn::sprite_items::cursor.tiles_item(), 2);
                            pickup_timer = -1;
                            ingredient = 0;
                            a_timeout = 50;
                            karmotrine_amount++;
                            shaker_pulse.set_tiles(bn::sprite_items::shaker_pulse.tiles_item(), 3);
                            shaker_pulse.set_visible(true);
                            pulse_flag = true;
                            bn::sound_items::pour.play(1.0);
                        }
                        pickup_timer++;
                        
                    }
                    
                break;
                
            }
            a_timeout++;
            total_amount = karmotrine_amount + delta_amount + bronson_amount + adelhyde_amount + flanergide_amount;
            if (total_amount >= 20)
            {
                ingredient = 0;
            }

            if(total_amount > 0 && ready_flag == false)
            {
                for(int c = total_amount; c < 10; ++c)
                {
                    shaker_bar_vector[c - 1].set_visible(false);
                }
            
                if (total_amount <= 10)
                    {
                        shaker_bar_vector[total_amount - 1].set_visible(true);
                        shaker_bar_vector[total_amount - 1].set_tiles(bn::sprite_items::shaker_bar.tiles_item(), 0);
                    }
                    else if(total_amount <= 20)
                    {
                        shaker_bar_vector[total_amount - 11].set_visible(true);
                        shaker_bar_vector[total_amount - 11].set_tiles(bn::sprite_items::shaker_bar.tiles_item(), 1);
                    }
            }
                


            if (flanergide_amount > 0 && flanergide_amount <= 20) // changing the amount indicators
            {
                if (flanergide_amount <= 10)
                {
                    flanergide_vector[flanergide_amount - 1].set_tiles(bn::sprite_items::amount.tiles_item(), 1);
                }
                else
                {
                    flanergide_vector[flanergide_amount - 11].set_tiles(bn::sprite_items::amount.tiles_item(), 2);
                }
                
            }
            if (adelhyde_amount > 0 && adelhyde_amount <= 20) // changing the amount indicators
            {
                if (adelhyde_amount <= 10)
                {
                    adelhyde_vector[adelhyde_amount - 1].set_tiles(bn::sprite_items::amount.tiles_item(), 4);
                }
                else
                {
                    adelhyde_vector[adelhyde_amount - 11].set_tiles(bn::sprite_items::amount.tiles_item(), 5);
                }
            }
            if (bronson_amount > 0 && bronson_amount <= 20) // changing the amount indicators
            {
                if (bronson_amount <= 10)
                {
                    bronson_vector[bronson_amount - 1].set_tiles(bn::sprite_items::amount.tiles_item(), 7);
                }
                else
                {
                    bronson_vector[bronson_amount - 11].set_tiles(bn::sprite_items::amount.tiles_item(), 8);
                }
            }
            if (delta_amount > 0 && delta_amount <= 20) // changing the amount indicators
            {
                if (delta_amount <= 10)
                {
                    delta_vector[delta_amount - 1].set_tiles(bn::sprite_items::amount.tiles_item(), 10);
                }
                else
                {
                    delta_vector[delta_amount - 11].set_tiles(bn::sprite_items::amount.tiles_item(), 11);
                }
            }
            if (karmotrine_amount > 0 && karmotrine_amount <= 20) // changing the amount indicators
            {
                if (karmotrine_amount <= 10)
                {
                    karmotrine_vector[karmotrine_amount - 1].set_tiles(bn::sprite_items::amount.tiles_item(), 13);
                }
                else
                {
                    karmotrine_vector[karmotrine_amount - 11].set_tiles(bn::sprite_items::amount.tiles_item(), 14);
                }
            }


            if(mixing_flag == true)
            {
                bn::fixed rotation_angle = shaker.rotation_angle();
                if(rotation_angle < 225 && mixing_limit == false)
                {
                    shaker.set_rotation_angle(rotation_angle + mixing_speed);
                }
                if(rotation_angle >= 225 && mixing_limit == false)
                {
                    mixing_limit = true;
                }
                if(rotation_angle > 135 && mixing_limit == true)
                {
                    shaker.set_rotation_angle(rotation_angle - mixing_speed);
                }
                if(rotation_angle <= 135 && mixing_limit == true)
                {
                    mixing_limit = false;
                }
                
                mixing_timer++;
                if(mixing_timer > 300)
                {
                    mixing_speed = 10;
                    blend_flag = 1;
                }
            }
            else if(mixing_mem == true)
            {
                mixing_timer = 0;
                mixing_limit = false;
                shaker.set_rotation_angle(180);
                mixing_speed = 4;
                drink_ready = true;
                mixing_mem = false;

            }
            mixing_mem = mixing_flag;

            if (drink_ready == true)
            {
                
                

                //shaker_pulse.set_tiles(bn::sprite_items::shaker_pulse.tiles_item(), 2);
                //shaker_pulse.set_visible(true);

                for (int c = 0; c < 10; ++c) // Changing the amount tiles to the defaults
                {
                    flanergide_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 0);
                    adelhyde_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 3);
                    bronson_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 6);
                    delta_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 9);
                    karmotrine_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 12);

                    shaker_bar_vector[c].set_visible(false); // turning off the shaker bar sprites
                }
                ice.set_tiles(bn::sprite_items::ice.tiles_item(), 1);
                age.set_tiles(bn::sprite_items::age.tiles_item(), 1);

                int drink_composition[] = {ice_flag, age_flag, adelhyde_amount, flanergide_amount, bronson_amount, delta_amount, karmotrine_amount, blend_flag};
                int matches[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

                for (int c = 0; c < 7; ++c) // comparing the resulting drink to the drinktionary
                {   
                    if (total_amount <= 10) // most of the normal drinks
                    {
                        if (game_vars::bad_touch[c] == drink_composition[c])
                        {
                            matches[0]++;
                        }
                        if (game_vars::beer[c] == drink_composition[c])
                        {
                            matches[1]++;
                        }
                        if (game_vars::bleeding_jane[c] == drink_composition[c])
                        {
                            matches[2]++;
                        }
                        if (game_vars::bloom_light[c] == drink_composition[c])
                        {
                            matches[3]++;
                        }
                        if (game_vars::blue_fairy[c] == drink_composition[c])
                        {
                            matches[4]++;
                        }
                        if (game_vars::branditini[c] == drink_composition[c])
                        {
                            matches[5]++;
                        }
                        if (game_vars::cobalt_velvet[c] == drink_composition[c])
                        {
                            matches[6]++;
                        }
                        if (game_vars::crevice_spike[c] == drink_composition[c])
                        {
                            matches[7]++;
                        }
                        if (game_vars::fluffy_dream[c] == drink_composition[c])
                        {
                            matches[8]++;
                        }
                        if (game_vars::fringe_weaver[c] == drink_composition[c])
                        {
                            matches[9]++;
                        }
                        if (game_vars::frothy_water[c] == drink_composition[c])
                        {
                            matches[10]++;
                        }
                        if (game_vars::grizzly_temple[c] == drink_composition[c])
                        {
                            matches[11]++;
                        }
                        if (game_vars::gut_punch[c] == drink_composition[c])
                        {
                            matches[12]++;
                        }
                        if (game_vars::mercury_blast[c] == drink_composition[c])
                        {
                            matches[14]++;
                        }
                        if (game_vars::moonblast[c] == drink_composition[c])
                        {
                            matches[15]++;
                        }
                        if (game_vars::piledriver[c] == drink_composition[c])
                        {
                            matches[18]++;
                        }
                        if (game_vars::sparkle_star[c] == drink_composition[c])
                        {
                            matches[19]++;
                        }
                        if (game_vars::sugar_rush[c] == drink_composition[c])
                        {
                            matches[20]++;
                        }
                        if (game_vars::sunshine_cloud[c] == drink_composition[c])
                        {
                            matches[21]++;
                        }
                        if (game_vars::suplex[c] == drink_composition[c])
                        {
                            matches[22]++;
                        }

                        // big drinks
                        if (game_vars::bad_touch_b[c] == drink_composition[c])
                        {
                            matches[25]++;
                        }
                        if (game_vars::beer_b[c] == drink_composition[c])
                        {
                            matches[26]++;
                        }
                        if (game_vars::bleeding_jane_b[c] == drink_composition[c])
                        {
                            matches[27]++;
                        }
                        if (game_vars::bloom_light_b[c] == drink_composition[c])
                        {
                            matches[28]++;
                        }
                        if (game_vars::blue_fairy_b[c] == drink_composition[c])
                        {
                            matches[29]++;
                        }
                        if (game_vars::branditini_b[c] == drink_composition[c])
                        {
                            matches[30]++;
                        }
                        if (game_vars::cobalt_velvet_b[c] == drink_composition[c])
                        {
                            matches[31]++;
                        }
                        if (game_vars::crevice_spike_b[c] == drink_composition[c])
                        {
                            matches[32]++;
                        }
                        if (game_vars::fluffy_dream_b[c] == drink_composition[c])
                        {
                            matches[33]++;
                        }
                        if (game_vars::fringe_weaver_b[c] == drink_composition[c])
                        {
                            matches[34]++;
                        }
                        if (game_vars::frothy_water_b[c] == drink_composition[c])
                        {
                            matches[35]++;
                        }
                        if (game_vars::grizzly_temple_b[c] == drink_composition[c])
                        {
                            matches[36]++;
                        }
                        if (game_vars::gut_punch_b[c] == drink_composition[c])
                        {
                            matches[37]++;
                        }
                        if (game_vars::mercury_blast_b[c] == drink_composition[c])
                        {
                            matches[38]++;
                        }
                        if (game_vars::moonblast_b[c] == drink_composition[c])
                        {
                            matches[39]++;
                        }
                        if (game_vars::piledriver_b[c] == drink_composition[c])
                        {
                            matches[40]++;
                        }
                        if (game_vars::sparkle_star_b[c] == drink_composition[c])
                        {
                            matches[41]++;
                        }
                        if (game_vars::sugar_rush_b[c] == drink_composition[c])
                        {
                            matches[42]++;
                        }
                        if (game_vars::sunshine_cloud_b[c] == drink_composition[c])
                        {
                            matches[43]++;
                        }
                        if (game_vars::suplex_b[c] == drink_composition[c])
                        {
                            matches[44]++;
                        }
                    
                    
                    }
                    if (total_amount > 10)
                    {
                        // naturally big drinks
                        if (game_vars::marsblast[c] == drink_composition[c])
                        {
                            matches[13]++;
                        }
                        if (game_vars::piano_man[c] == drink_composition[c])
                        {
                            matches[16]++;
                        }
                        if (game_vars::piano_woman[c] == drink_composition[c])
                        {
                            matches[17]++;
                        }
                        if (game_vars::zen_star[c] == drink_composition[c])
                        {
                            matches[23]++;
                        }
                        if (game_vars::flaming_moai[c] == drink_composition[c])
                        {
                            matches[24]++;
                        }

                        // optional karmotrine overflow
                        if (game_vars::blue_fairy[c] == drink_composition[c])
                        {
                            matches[4]++;
                        }
                        if (game_vars::crevice_spike[c] == drink_composition[c])
                        {
                            matches[7]++;
                        }
                        if (game_vars::fluffy_dream[c] == drink_composition[c])
                        {
                            matches[8]++;
                        }
                        if (game_vars::gut_punch[c] == drink_composition[c])
                        {
                            matches[12]++;
                        }
                        if (game_vars::sparkle_star[c] == drink_composition[c])
                        {
                            matches[19]++;
                        }
                        if (game_vars::sugar_rush[c] == drink_composition[c])
                        {
                            matches[20]++;
                        }
                        if (game_vars::sunshine_cloud[c] == drink_composition[c])
                        {
                            matches[21]++;
                        }

                        // big drinks
                        if (game_vars::bad_touch_b[c] == drink_composition[c])
                        {
                            matches[25]++;
                        }
                        if (game_vars::beer_b[c] == drink_composition[c])
                        {
                            matches[26]++;
                        }
                        if (game_vars::bleeding_jane_b[c] == drink_composition[c])
                        {
                            matches[27]++;
                        }
                        if (game_vars::bloom_light_b[c] == drink_composition[c])
                        {
                            matches[28]++;
                        }
                        if (game_vars::blue_fairy_b[c] == drink_composition[c])
                        {
                            matches[29]++;
                        }
                        if (game_vars::branditini_b[c] == drink_composition[c])
                        {
                            matches[30]++;
                        }
                        if (game_vars::cobalt_velvet_b[c] == drink_composition[c])
                        {
                            matches[31]++;
                        }
                        if (game_vars::crevice_spike_b[c] == drink_composition[c])
                        {
                            matches[32]++;
                        }
                        if (game_vars::fluffy_dream_b[c] == drink_composition[c])
                        {
                            matches[33]++;
                        }
                        if (game_vars::fringe_weaver_b[c] == drink_composition[c])
                        {
                            matches[34]++;
                        }
                        if (game_vars::frothy_water_b[c] == drink_composition[c])
                        {
                            matches[35]++;
                        }
                        if (game_vars::grizzly_temple_b[c] == drink_composition[c])
                        {
                            matches[36]++;
                        }
                        if (game_vars::gut_punch_b[c] == drink_composition[c])
                        {
                            matches[37]++;
                        }
                        if (game_vars::mercury_blast_b[c] == drink_composition[c])
                        {
                            matches[38]++;
                        }
                        if (game_vars::moonblast_b[c] == drink_composition[c])
                        {
                            matches[39]++;
                        }
                        if (game_vars::piledriver_b[c] == drink_composition[c])
                        {
                            matches[40]++;
                        }
                        if (game_vars::sparkle_star_b[c] == drink_composition[c])
                        {
                            matches[41]++;
                        }
                        if (game_vars::sugar_rush_b[c] == drink_composition[c])
                        {
                            matches[42]++;
                        }
                        if (game_vars::sunshine_cloud_b[c] == drink_composition[c])
                        {
                            matches[43]++;
                        }
                        if (game_vars::suplex_b[c] == drink_composition[c])
                        {
                            matches[44]++;
                        }
                    }
                    
                    
                }
                for (int c = 0; c < 48; c++) // searching for the perfect match
                {
                    if (matches[c] == 7)
                    {
                        result = c + 1;
                        karmotrine_mem += karmotrine_amount;
                        success_flag = true;
                    }
                }
                int check = drink_composition[2] + drink_composition[3] + drink_composition[4] + drink_composition[5];
                if (result == 0 && karmotrine_amount > 0) // searching for the fuzzy match (optional karmotrine)
                {
                    for (int c = 0; c < 48; c++)
                {
                    if (matches[c] == 6) 
                    {
                        if (c == 4 || c == 7 || c == 8 || c == 12 || c == 19 || c == 20 || c == 21 || c == 29 || c == 32 || c == 33 || c == 37 || c == 41 || c == 42 || c == 43)
                        {
                            result = c + 1;
                            karmotrine_mem += karmotrine_amount;
                            success_flag = true;
                        }
                        
                        
                    }
                }
                }
                if (result == 0)
                {
                    fail_flag = true;
                }
                //the drink sets to glitch automatically if no match is found (result == 0 ==> drinks_vector[0])
                shaker.set_visible(false);
                drink_name.set_visible(true);
                drink_name.generate(-11, 68, TextManager::get_drink_name(result), drink_name_vector); // writing the resulting drink's name
                //bn::sound_items::success.play(1.0);
                order = result;
                switch (result) // drawing the correct sprite
                {
                case 0:
                    drink.set_item(bn::sprite_items::glitchbottle);
                    drink.set_visible(true);
                break;

                case 1:
                    drink.set_item(bn::sprite_items::bad_touch);
                    drink.set_visible(true);
                break;

                case 2:
                    drink.set_item(bn::sprite_items::beer);
                    drink.set_visible(true);
                break;

                case 3:
                    drink.set_item(bn::sprite_items::bleeding_jane);
                    drink.set_visible(true);
                break;

                case 4:
                    drink.set_item(bn::sprite_items::bloom_light);
                    drink.set_visible(true);
                break;

                case 5:
                    drink.set_item(bn::sprite_items::blue_fairy);
                    drink.set_visible(true);
                break;

                case 6:
                    drink.set_item(bn::sprite_items::branditini);
                    drink.set_visible(true);
                break;

                case 7:
                    drink.set_item(bn::sprite_items::cobalt_velvet);
                    drink.set_visible(true);
                break;

                case 8:
                    drink.set_item(bn::sprite_items::crevice_spike);
                    drink.set_visible(true);
                break;

                case 9:
                    drink.set_item(bn::sprite_items::fluffy_dream);
                    drink.set_visible(true);
                break;

                case 10:
                    drink.set_item(bn::sprite_items::fringe_weaver);
                    drink.set_visible(true);
                break;

                case 11:
                    drink.set_item(bn::sprite_items::beer);
                    drink.set_visible(true);
                break;

                case 12:
                    drink.set_item(bn::sprite_items::grizzly_temple);
                    drink.set_visible(true);
                break;

                case 13:
                    drink.set_item(bn::sprite_items::gut_punch);
                    drink.set_visible(true);
                break;

                case 14:
                    drink.set_item(bn::sprite_items::marsblast);
                    drink.set_visible(true);
                break;

                case 15:
                    drink.set_item(bn::sprite_items::mercury_blast);
                    drink.set_visible(true);
                break;

                case 16:
                    drink.set_item(bn::sprite_items::moonblast);
                    drink.set_visible(true);
                break;

                case 17:
                    drink.set_item(bn::sprite_items::piano_man);
                    drink.set_visible(true);
                break;

                case 18:
                    drink.set_item(bn::sprite_items::piano_woman);
                    drink.set_visible(true);
                break;

                case 19:
                    drink.set_item(bn::sprite_items::piledriver);
                    drink.set_visible(true);
                break;

                case 20:
                    drink.set_item(bn::sprite_items::sparkle_star);
                    drink.set_visible(true);
                break;

                case 21:
                    drink.set_item(bn::sprite_items::sugar_rush);
                    drink.set_visible(true);
                break;

                case 22:
                    drink.set_item(bn::sprite_items::sunshine_cloud);
                    drink.set_visible(true);
                break;

                case 23:
                    drink.set_item(bn::sprite_items::suplex);
                    drink.set_visible(true);
                break;

                case 24:
                    drink.set_item(bn::sprite_items::zen_star);
                    drink.set_visible(true);
                break;

                case 25:
                    drink.set_item(bn::sprite_items::flaming_moai);
                    drink.set_visible(true);
                break;

                case 26:
                    drink.set_item(bn::sprite_items::bad_touch);
                    drink.set_visible(true);
                break;

                case 27:
                    drink.set_item(bn::sprite_items::beer);
                    drink.set_visible(true);
                break;

                case 28:
                    drink.set_item(bn::sprite_items::bleeding_jane);
                    drink.set_visible(true);
                break;

                case 29:
                    drink.set_item(bn::sprite_items::bloom_light);
                    drink.set_visible(true);
                break;

                case 30:
                    drink.set_item(bn::sprite_items::blue_fairy);
                    drink.set_visible(true);
                break;

                case 31:
                    drink.set_item(bn::sprite_items::branditini);
                    drink.set_visible(true);
                break;

                case 32:
                    drink.set_item(bn::sprite_items::cobalt_velvet);
                    drink.set_visible(true);
                break;

                case 33:
                    drink.set_item(bn::sprite_items::crevice_spike);
                    drink.set_visible(true);
                break;

                case 34:
                    drink.set_item(bn::sprite_items::fluffy_dream);
                    drink.set_visible(true);
                break;

                case 35:
                    drink.set_item(bn::sprite_items::fringe_weaver);
                    drink.set_visible(true);
                break;

                case 36:
                    drink.set_item(bn::sprite_items::beer);
                    drink.set_visible(true);
                break;

                case 37:
                    drink.set_item(bn::sprite_items::grizzly_temple);
                    drink.set_visible(true);
                break;

                case 38:
                    drink.set_item(bn::sprite_items::gut_punch);
                    drink.set_visible(true);
                break;

                case 39:
                    drink.set_item(bn::sprite_items::mercury_blast);
                    drink.set_visible(true);
                break;

                case 40:
                    drink.set_item(bn::sprite_items::moonblast);
                    drink.set_visible(true);
                break;

                case 41:
                    drink.set_item(bn::sprite_items::piledriver);
                    drink.set_visible(true);
                break;

                case 42:
                    drink.set_item(bn::sprite_items::sparkle_star);
                    drink.set_visible(true);
                break;

                case 43:
                    drink.set_item(bn::sprite_items::sugar_rush);
                    drink.set_visible(true);
                break;

                case 44:
                    drink.set_item(bn::sprite_items::sunshine_cloud);
                    drink.set_visible(true);
                break;

                case 45:
                    drink.set_item(bn::sprite_items::suplex);
                    drink.set_visible(true);
                break;
                
                
                }

                flanergide_amount = 0;
                adelhyde_amount = 0;
                bronson_amount = 0;
                delta_amount = 0;
                karmotrine_amount = 0;
                ice_flag = 0;
                age_flag = 0;
                blend_flag = 0;
                total_amount = 0;
                mixing_flag = false;
                mixing_mem = false;
                mixing_limit = false;
                mixing_timer = 0;
                mixing_speed = 4;
                //pulse_flag = true;
                pulse_timer = 0;
                shaker.set_rotation_angle(180);
                drink_ready = false;
                ready_flag = true;
            }

            if(pulse_flag == true)
            {
                switch(pulse_timer)
                {
                    case 0:
                        shaker_pulse.set_scale(1.1);
                    break;
                    case 1:
                        shaker_pulse.set_scale(1.2);
                    break;
                    case 3:
                        shaker_pulse.set_scale(1.3);
                    break;
                    case 5:
                        shaker_pulse.set_scale(1.4);
                    break;
                    case 7:
                        shaker_pulse.set_scale(1.5);
                    break;
                    case 9:
                        shaker_pulse.set_scale(1.6);
                    break;
                    case 11:
                        shaker_pulse.set_scale(1.7);
                    break;
                    case 13:
                        shaker_pulse.set_scale(1.8);
                    break;
                    case 15:
                        shaker_pulse.set_scale(1);
                        shaker_pulse.set_visible(false);
                        pulse_timer = -1;
                        pulse_flag = false;
                    break;
                }
                pulse_timer++;
            }

            if (success_flag == true) // generate the success text
            {
            switch (pulse_timer)
            {
                case 0:
                    success_spr.set_item(bn::sprite_items::success);
                    success_spr.set_tiles(bn::sprite_items::success.tiles_item(), 0);
                    success_spr.set_visible(true);
                    success_y = 28;
                break;

                case 5:
                    success_spr.set_item(bn::sprite_items::success);
                    success_spr.set_tiles(bn::sprite_items::success.tiles_item(), 1);
                    success_spr.set_visible(true);
                break;

                case 10:
                    success_spr.set_item(bn::sprite_items::success);
                    success_spr.set_tiles(bn::sprite_items::success.tiles_item(), 0);
                    success_spr.set_visible(true);
                break;

                case 15:
                    success_spr.set_item(bn::sprite_items::success);
                    success_spr.set_tiles(bn::sprite_items::success.tiles_item(), 1);
                    success_spr.set_visible(true);
                break;

                case 20:
                    success_spr.set_item(bn::sprite_items::success);
                    success_spr.set_tiles(bn::sprite_items::success.tiles_item(), 2);
                    success_spr.set_visible(true);
                break;

                case 25:
                    success_spr.set_item(bn::sprite_items::success);
                    success_spr.set_tiles(bn::sprite_items::success.tiles_item(), 3);
                    success_spr.set_visible(true);
                break;

                case 30:
                    success_spr.set_item(bn::sprite_items::success);
                    success_spr.set_tiles(bn::sprite_items::success.tiles_item(), 2);
                    success_spr.set_visible(true);
                break;

                case 35:
                    success_spr.set_item(bn::sprite_items::success);
                    success_spr.set_tiles(bn::sprite_items::success.tiles_item(), 3);
                    success_spr.set_visible(true);
                break;

                case 40:
                    success_spr.set_item(bn::sprite_items::success);
                    success_spr.set_tiles(bn::sprite_items::success.tiles_item(), 0);
                    success_spr.set_visible(false);
                    pulse_timer = -1;
                    success_flag = false;
                break;
            }
            pulse_timer++;
            success_y--;
            success_spr.set_y(success_y);
        }

        if (fail_flag == true) // generate the fail text
            {
            switch (pulse_timer)
            {
                case 0:
                    success_spr.set_item(bn::sprite_items::fail);
                    success_spr.set_tiles(bn::sprite_items::fail.tiles_item(), 0);
                    success_spr.set_visible(true);
                    success_y = 28;
                break;

                case 5:
                    success_spr.set_item(bn::sprite_items::fail);
                    success_spr.set_tiles(bn::sprite_items::fail.tiles_item(), 1);
                    success_spr.set_visible(true);
                break;

                case 10:
                    success_spr.set_item(bn::sprite_items::fail);
                    success_spr.set_tiles(bn::sprite_items::fail.tiles_item(), 0);
                    success_spr.set_visible(true);
                break;

                case 15:
                    success_spr.set_item(bn::sprite_items::fail);
                    success_spr.set_tiles(bn::sprite_items::fail.tiles_item(), 1);
                    success_spr.set_visible(true);
                break;

                case 20:
                    success_spr.set_item(bn::sprite_items::fail);
                    success_spr.set_tiles(bn::sprite_items::fail.tiles_item(), 2);
                    success_spr.set_visible(true);
                break;

                case 25:
                    success_spr.set_item(bn::sprite_items::fail);
                    success_spr.set_tiles(bn::sprite_items::fail.tiles_item(), 3);
                    success_spr.set_visible(true);
                break;

                case 30:
                    success_spr.set_item(bn::sprite_items::fail);
                    success_spr.set_tiles(bn::sprite_items::fail.tiles_item(), 2);
                    success_spr.set_visible(true);
                break;

                case 35:
                    success_spr.set_item(bn::sprite_items::fail);
                    success_spr.set_tiles(bn::sprite_items::fail.tiles_item(), 3);
                    success_spr.set_visible(true);
                break;

                case 40:
                    success_spr.set_item(bn::sprite_items::fail);
                    success_spr.set_tiles(bn::sprite_items::fail.tiles_item(), 0);
                    success_spr.set_visible(false);
                    pulse_timer = -1;
                    fail_flag = false;
                break;
            }
            pulse_timer++;
            success_y--;
            success_spr.set_y(success_y);
        }

        if (ready_flag == true) // allowing a reset even if thereare no ingredients if the drink is ready
        {
            reset_allowed = true;
        }
        else if (total_amount > 0)// allowing a reset when there are ingredients if it's not ready
        {
            reset_allowed = true;
        }
        else
        {
            reset_allowed = false;
        }


            if(bn::keypad::a_pressed() && ready_flag == false && mixing_flag == false)
            {
                //if (a_timeout > 25) // waiting for the anim to stop playing
                //{
                    switch (cursor_x)
                    {
                        case first_col:
                        if (cursor_y == first_row)
                        {
                           ingredient = 1; // ice
                        }
                        else
                        {
                           ingredient = 2; // age
                        }
                        break;

                        case second_col:
                        if (cursor_y == other_rows)
                        {
                            ingredient = 3; // adelhyde
                        }
                        else
                        {
                            ingredient = 4; // flanergide
                        }
                        break;

                        case third_col:
                           ingredient = 5; // bronson
                        break;

                        case fourth_col:
                        if (cursor_y == other_rows)
                        {
                           ingredient = 6; // delta
                        }
                        else
                        {
                           ingredient = 7; // karmotrine
                        }
                        break;
                    }
                //}
            }

            if(bn::keypad::left_pressed() && ingredient == 0)
            {
                if (ingredient == 0)
                {
                    switch (cursor_x) // moving a cursor in x axis
                    {
                        case fourth_col:
                            if(cursor_y == other_second_rows) // from karmotrine to flanergide
                            {
                                cursor_x = second_col;
                                cursor.set_x(cursor_x);
                            }
                            else // from delta to bronson
                            {
                                cursor_x = third_col;
                                cursor.set_x(cursor_x);
                            }
                        break;

                        case third_col:
                            cursor_x = second_col;
                            cursor.set_x(cursor_x);
                        break;

                        case second_col:
                            if (cursor_y == other_rows)
                            {
                                cursor_x = first_col;
                                cursor_y = first_row;
                                cursor.set_x(cursor_x);
                                cursor.set_y(cursor_y);
                            }
                            else
                            {
                                cursor_x = first_col;
                                cursor_y = second_row;
                                cursor.set_x(cursor_x);
                                cursor.set_y(cursor_y);
                            }
                            
                        break;

                        case first_col:
                            // error SFX
                        break;
                    }
                }
            }

            if(bn::keypad::right_pressed() && ingredient == 0)
            {
                if (ingredient == 0)
                {
                    switch (cursor_x) // moving a cursor in x axis
                    {
                        case fourth_col:
                            // error SFX
                        break;

                        case third_col:
                            cursor_x = fourth_col;
                            cursor.set_x(cursor_x);
                        break;

                        case second_col:
                            if(cursor_y == other_second_rows) // from flanergide to karmotrine
                            {
                                cursor_x = fourth_col;
                                cursor.set_x(cursor_x);
                            }
                            else // from adelhyde to bronson
                            {
                                cursor_x = third_col;
                                cursor.set_x(cursor_x);
                            }
                        break;

                        case first_col:
                            if (cursor_y == first_row)
                            {
                                cursor_x = second_col;
                                cursor_y = other_rows;
                                cursor.set_x(cursor_x);
                                cursor.set_y(cursor_y);
                            }
                            else
                            {
                                cursor_x = second_col;
                                cursor_y = other_second_rows;
                                cursor.set_x(cursor_x);
                                cursor.set_y(cursor_y);
                            }
                        break;
                    }
                }
            }

            if(bn::keypad::up_pressed() && ingredient == 0)
            {
                switch(cursor_y)
                {
                    case second_row:
                        cursor_y = first_row;
                        cursor.set_y(cursor_y);
                    break;

                    case other_second_rows:
                        cursor_y = other_rows;
                        cursor.set_y(cursor_y);
                    break;

                    case first_row:
                        // error SFX
                    break;

                    case other_rows:
                        // error SFX
                    break;
                }
            }

            if(bn::keypad::down_pressed() && ingredient == 0)
            {
                switch(cursor_y)
                {
                    case second_row:
                        // error SFX
                    break;

                    case other_second_rows:
                        // error SFX
                    break;

                    case first_row:
                        cursor_y = second_row;
                        cursor.set_y(cursor_y);
                    break;

                    case other_rows:
                        if (cursor_x != third_col)
                        {
                            cursor_y = other_second_rows;
                            cursor.set_y(cursor_y);
                        }
                        
                    break;
                }
            }

            if(bn::keypad::b_pressed() && ingredient == 0 && total_amount > 0)
            {
                mixing_flag = !mixing_flag;
                bn::sound_items::success.play(1.0); // playing the sound if the drink starts mixing
                
            }
            if(bn::keypad::b_pressed() && ready_flag == true)
            {
                line += 2;
                pos++;
                karmotrine_memory += karmotrine_mem;
                pass_flag = true;
                //frame.set_visible(false);
                //textbox.set_visible(false);
            }

            if(bn::keypad::r_pressed() && ingredient == 0 && reset_allowed == true && pulse_flag == false && success_flag == false && fail_flag == false)
            {
                flanergide_amount = 0;
                adelhyde_amount = 0;
                bronson_amount = 0;
                delta_amount = 0;
                karmotrine_amount = 0;
                ice_flag = 0;
                age_flag = 0;
                blend_flag = 0;
                total_amount = 0;
                mixing_flag = false;
                mixing_mem = false;
                mixing_limit = false;
                mixing_timer = 0;
                mixing_speed = 4;
                drink_ready = false;
                pulse_flag = true;
                pulse_timer = 0;
                shaker.set_rotation_angle(180);
                ready_flag = false;
                result = 0;
                
                for (int c = 0; c < 10; ++c) // Changing the amount tiles to the defaults
                {
                    flanergide_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 0);
                    adelhyde_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 3);
                    bronson_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 6);
                    delta_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 9);
                    karmotrine_vector[c].set_tiles(bn::sprite_items::amount.tiles_item(), 12);

                    shaker_bar_vector[c].set_visible(false); // turning off the shaker bar sprites
                }
                ice.set_tiles(bn::sprite_items::ice.tiles_item(), 1);
                age.set_tiles(bn::sprite_items::age.tiles_item(), 1);
                drink.set_visible(false);
                drink_name.generate(-11, 68, "", drink_name_vector);
                for (int i = 0; i < drink_name_vector.size(); i++)
                {
                    drink_name_vector[i].set_visible(false);
                }
                
                //drink_name.set_visible(false);
                
                shaker.set_visible(true);
                shaker_pulse.set_visible(true);
                shaker_pulse.set_tiles(bn::sprite_items::shaker_pulse.tiles_item(), 2);
                bn::sound_items::reset.play(1.0);
                
                
                
                
                
                
            }

            if(bn::keypad::select_pressed() && ingredient == 0) // displaying memory
            {
                memory_flag = !memory_flag;
                if(memory_flag == true)
                {
                    textbox.set_visible(true);
                    for(int c = 0; c < text_sprites.size(); ++c)
                        {
                            text_sprites[c].set_visible(true);
                        }
                }
                else
                {
                    textbox.set_visible(false);
                    for(int c = 0; c < text_sprites.size(); ++c)
                        {
                            text_sprites[c].set_visible(false);
                        }
                }
            }

            bn::core::update();
        }     
        activity = 1; // returning to the barground
    }

    void barground_to_mixing()
    {
        int timer = 0;
        int bluebg_y = -160;

        bn::regular_bg_ptr bg_bg = bn::regular_bg_items::bg.create_bg(0, -15);
        bn::regular_bg_ptr bluebg = bn::regular_bg_items::bluebg.create_bg(0, bluebg_y);
        //bluebg.blending(false);

        while (timer < 90)
        {
            bluebg_y += 2;
            bluebg.set_y(bluebg_y);
            timer++;
            bn::core::update();
        }
        bn::sound_items::reset.play(1.0);
    }

    void break_ph()
    {
        bool flag = false;
        bool fade_in = true;
        bool fade_out = false;
        bool normal = false;
        bn::fixed alpha = 1.0;
        bn::regular_bg_ptr break_bg = bn::regular_bg_items::break_placeholder.create_bg(0, 0);
        bn::bg_palette_ptr break_bg_palette = break_bg.palette();
        break_bg_palette.set_fade_intensity(alpha);

        while(flag == false)
        {
            if (fade_in == true) // fading in
            {
                if (alpha > 0.0)
                        {
                            alpha -= 0.01;
                            if(alpha<0.0)
                            {
                                alpha = 0.0;
                            }
                            break_bg_palette.set_fade_intensity(alpha);
                        }
                        else
                        {
                            fade_in = false;
                            normal = true;
                        }
            }
            else if (fade_out == true) // fading out
            {
                if (normal == true)
                {
                    alpha = 0.0;
                    normal = false;
                }
                else
                {
                    if (alpha < 1.0)
                        {
                            alpha += 0.01;
                            if(alpha > 1.0)
                            {
                                alpha = 1.0;
                            }
                            break_bg_palette.set_fade_intensity(alpha);
                        }
                        else // wiping vars and moving to the next half of the day
                        {
                            break_bg.set_visible(false);
                            pos = 0;
                            //day++;
                            order = 0;
                            line = 0;
                            karmotrine_memory = 0;
                            karmotrine_prev = 0;
                            drunk = false;
                            play_flag = false;
                            fade_out = false;
                            activity = 1;
                            flag = true;
                        }
                }
                
            }

            if (bn::keypad::a_pressed() || bn::keypad::start_pressed())
            {
                fade_out = true;
            }
            bn::core::update();
        }
        
    }
}



int main()
{
    bn::core::init();
    while(true)
    {
        switch (activity)
        {
            case 1:
                switch (day)
                {
                    case 0:
                    prologue();
                    break;

                    case 1:
                    day_1();
                    break;

                    case 2:
                    day_1_2();
                    break;
                }
            break;

            case 2:
                barground_to_mixing();
                mixing();
                activity = 1;
            break;

            case 3:
                break_ph();
                activity = 1;
                day = 2;
            break;
        }

        bn::core::update();
    }
    
    // while(true)
    // {
    //     //prologue();
    //     //bn::music_items::last_call.play();
    //     day_1();
       // barground_to_mixing();
        //mixing();
    //     //barground_to_mixing();
    //     //mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
    //     // mixing();
    //     // day_1();
        
    // }
}
