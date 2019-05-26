#!/usr/bin/python
# -*- coding: UTF-8 -*-
import sys
import os
#test function  

print("in python function:")  
def add(a,b):  
    print("in python function add")  
    print("a = " + str(a))  
    print("b = " + str(b))  
    print("ret = " + str(a+b))  
  
def foo(a):  
    print("in python function foo")  
    print("a = " + str(a))  
    print("ret = " + str(a * a))  
 

def multiply(a,b):
    print("Will compute", a, "times", b)
    c = 0
    for i in range(0, a):
        c = c + b
    return c

if __name__ == '__main__':
    multiply(3, 3)
    add(4,7)
    # print(__name__)


#class guestlist:  
#    def __init__(self):  
#        print("aaaa")  
#    def p():  
#      print("bbbbb")  
#    def __getitem__(self, id):  
#      return "ccccc"  
#def update():  
#    guest = guestlist()  
#    print(guest['aa'])  
#  
#update()
