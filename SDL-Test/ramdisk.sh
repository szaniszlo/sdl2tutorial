#!/bin/sh

#  ramdisk.sh
#  SDL-Test
#
#  Created by Stefan Szaniszlo on 04/12/2021.
#

#
# create and mount a ramdisk
#
function mountRamdisk() {
  local -r mount_point="$1"
  local -r size_blocks="$2"

  local -r volume_name=$(basename "${mount_point}")
  local -r base=$(mount | grep "${volume_name}")
  echo "Volume: '${volume_name}'"
  if [ -z "$base" ] ; then
    echo "Creating RAM disk for $mount_point"
    ramdisk=$(hdid -nomount "ram://${size_blocks}" | xargs)
    if [ -n "${ramdisk}" ] ; then
      echo "Mounting '${ramdisk}' at '${mount_point}'"
      newfs_hfs -v "${volume_name}" "${ramdisk}" || return $?
      diskutil mount -mountPoint "${mount_point}" "${ramdisk}" || return $?
      echo "Mount successful!"
    fi
  else
    echo "RAM disk already mounted for $mount_point"
  fi
}

# create ramdisk for X-Code
mountRamdisk "~/Library/Developer/Xcode/DerivedData" "4194304" # 512 byte sectors = 2GB
