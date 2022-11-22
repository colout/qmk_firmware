Based on VIA keymap for Sofle

Will need to run separately for left and right (see ../colout-left and ../colout-right)

firmware has 820 free
need 532 more
need 1352 total free


combined printlns on wpm 854

layer statuses set as char array in switch statemetn with strcopy 828

remove scroll and numlock.  remove extra printline \n\n in layers 904

refactored mouse macro to use functions and counts where possible 1122.  230 to go!


removed global var wpm.  made private.  1222.  130 g go

removed light layers - 1244

statics don't do anything in oled or mouse automation
decremental for loop 1252
host_system_send instead of SEND STRING 1394