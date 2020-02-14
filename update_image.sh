#!/bin/bash

sudo losetup /dev/loop18 floppy.img
sudo mount /dev/loop18 /mnt
sudo cp src/kernel /mnt/kernel
sudo umount /dev/loop18
sudo losetup -d /dev/loop18
