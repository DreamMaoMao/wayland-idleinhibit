# wayland-idleinhibit
Triggers an idle inhibit


# install 
```
meson build -Dprefix=/usr/
sudo ninja -C build instal
```

# usage
```
wayland-idleinhibit
```

# example(when download or upload something)
```bash
#!/usr/bin/bash

DEVICE=$(ls /sys/class/net | grep ^w)

while true
do
    net_text=$( sar -n DEV 1 1 | grep $DEVICE |grep -E "Average|平均时间" | awk 'BEGIN{c=" "}{print  $5""c""$6 }' )
    upload_speed=$(echo $net_text | cut -d " " -f 2 | cut -d "." -f 1)
    download_speed=$(echo $net_text | cut -d " " -f 1 | cut -d "." -f 1)
    echo $upload_speed
    echo $download_speed
    if (( $download_speed > 100 ));then
        wayland-idleinhibit
    elif (( $upload_speed > 100 ));then
        wayland-idleinhibit
    fi
    sleep 60s
done
```
