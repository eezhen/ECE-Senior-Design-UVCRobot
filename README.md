**# ECE-Senior-Design-UVCRobot**
**Hardwares:**
- Raspberry Pi 4 (2 GB more is better) with SD cards (32 GB storage is enough)
- Kinect V1                   (need a specialized adapter for connecting to RPi and being powered at the same time)
- Arduino Mega 2560           (sufficient digital pins for sensors and modules, other Arduino will work if less pins are used) 
- DC Motors
- Motor Drivers TB6612FNG     (others are fine)
- Ultrasonic Sensors HC-SR04  (as long as it's distance sensing)
- Relay Module KY-019 5V      (others are fine)


**Design Wiki site:**


**Softwares:**
**For USB serial conmmunication (RPi to Ardu to RPi):**
1. Make sure Arduino is written 
(It can be tested with any test.ino in my folders, be careful with wiring and pins defining)

2. Install pySerial on Raspberry Pi 4
https://roboticsbackend.com/raspberry-pi-arduino-serial-communication/#Serial_via_USB

3. Execute python file on RPi side to see the serial communnication
(the only one .py file under my folders)

**For Mappings:**
1. Install Ubuntu 20.04 Desktop on Raspberry Pi 4
(ROS Noetic is primarily targeted at the Ubuntu 20.04 release, Desktop version is for GUI software)

2. Install Ubuntu 20.04 Desktop on your virtual machine 
(because freenect itself is already memory consuming, others are better be run on the VM side)
https://ubuntu.tutorials24x7.com/blog/how-to-install-ubuntu-20-04-lts-on-windows-using-vmware-workstation-player

3. Install libfreenect on Raspberry Pi 4 
(all can be done by the series of linux commands)
https://aibegins.net/2020/11/22/give-your-next-robot-3d-vision-kinect-v1-with-ros-noetic/
https://www.hackster.io/dmitrywat/rgb-d-slam-with-kinect-on-raspberry-pi-4-ros-melodic-ace795

4. Install ROS Noetic on Raspberry Pi 4 and virtual machine 
(all can be done by the series of linux commands)
http://wiki.ros.org/noetic/Installation/Ubuntu

5. Properly Source catkin workplace
http://wiki.ros.org/catkin/Tutorials/create_a_workspace

6. Install RTAB-MAP ROS
(sudo apt-get install ros-noetic-rtabmap-ros)

7. On RPi
  1st Terminal:
  $ cd catkin_ws
  $ catkin_make
  $ source devel/setup.bash
  $ export ROS_MASTER_URI=http://RPi-IP:11311
  $ export ROS_IP=RPi-IP
  $ roslaunch freenect_launch freenect.launch depth_registration:=true

  2nd Terminal:
  $ roslaunch rtabmap_ros rgbd_mapping.launch rtabmap_args:="--delete_db_on_start rtabmapviz:=false

8. On VM
  $ export ROS_MASTER_URI=http://RPi-IP:11311
  $ export ROS_IP=VM-IP
  $ rviz
  Then configure the MapGraph and MapCloud settings to see mapping start
