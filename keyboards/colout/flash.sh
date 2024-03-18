# login to root before running
sudo whoami

qmk compile -kb colout/rev1 -km colout-homerow

sleep 3

sudo umount /dev/usb
sudo mount /dev/sda1 /mnt/usb
sudo mount /dev/sdb1 /mnt/usb
sudo cp ~/git/qmk_firmware/.build/crkbd_rev1_colout-homerow.uf2 /mnt/usb

