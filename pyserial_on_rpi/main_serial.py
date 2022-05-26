#!/usr/bin/env python3
import serial
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0',9600,timeout=1) # ls /dev/tty* to find what exactly it is called on your device, mine is ttyACM0
    ser.reset_input_buffer()
    print(" 1 for Remote Keyboard Control ")
    mode = input(" 2 for Auto Navigation ------ ")
    if mode == '1':
            print(" == UVC Robot under Remote Control mode == ")
            while True:
                cmd = input("Tell Ardu what to do = ")
                print()
                if cmd == 'w' or 'a' or 's' or 'd' or 'u':
                    ser.write(cmd.encode('utf-8'))
                else:
                    print("[Remote Control]: Invalid Input")
                time.sleep(1)
    elif mode == '2':
        print(" == UVC Robot under Auto Navigation Mode == ")
        autokey = 'n'
        while True:
            ser.write(autokey.encode('utf-8'))
            time.sleep(1)
    else:
        print("[Mode Selection]: Invalid Input: Try to input 1 or 2")
