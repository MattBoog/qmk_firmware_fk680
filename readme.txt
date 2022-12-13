The first time you flash this code press the reset button on the pcb twice. Then it will show up as a drive on your pc where you can paste the .uf2 file.

After that, just hold escape while plugging it in or use the reset combination (fn + Lctrl).

Be aware that this is a work in progress and has only been aimed at the "default" keymap for now. "via" should work as well, but that has to be tested again first. 

To compile:
Set this repo as your qmk location in qmk msys using "qmk setup -H <filepath>"
Then type "qmk compile -kb zhaqian/fk680 -km default"