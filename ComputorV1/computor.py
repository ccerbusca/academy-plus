#!/usr/bin/python
from __future__ import print_function
from math import sqrt
import sys, re

def err(str):
    print (str)
    sys.exit(-42);

def print_csolution(x):
    if x.real.is_integer():
        print (str(x.real) + (" + " if x.imag >= 0 else " - "), end="")
    else:
        print ("{0:.6f}{1}".format(x.real, " + " if x.imag >= 0 else " - "), end="")
    if x.imag.is_integer():
        print (str(x.imag if x.imag >= 0 else -x.imag) + "i")
    else:
        print ("{0:.6f}i".format(x.imag if x.imag >= 0 else -x.imag))

def print_rsolution(x):
    if not x.is_integer():
        print ("{0:.6f}".format(x))
    else:
        print (x)

def process_input(i):
    i = [j.strip() for j in i.split("*")]
    if "." in i[0]:
        coef = float(i[0])
    else:
        coef = int(i[0])
    return coef, int(i[1][-1])

def validation(str):
    pattern = "^(?:(?:[+-]?(?:\d{1,10}|\d{1,10}.\d{1,6})\s\*\s)X\^\d{1,10})" \
              "(?:\s[+-]\s(?:[+-]?(?:\d{1,10}|\d{1,10}.\d{1,6})\s\*\s)X\^\d{1,10})*\s?=\s?" \
              "(?:(?:(?:[+-]?(?:\d{1,10}|\d{1,10}.\d{1,6})\s\*\s)X\^\d{1,10})" \
              "(?:\s[+-]\s(?:[+-]?(?:\d{1,10}|\d{1,10}.\d{1,6})\s\*\s)X\^\d{1,10})*|0)$"
    regex = re.compile(pattern)
    if not regex.match(str):
        err("Wrong input")

if len(sys.argv) != 2:
    err("Wrong number of arguments")

validation(sys.argv[1])

tab = [i.strip() for i in sys.argv[1].split("=")]

snd_part_is_good = True
if tab[1] == "0":
    snd_part_is_good = False

tab[0] = tab[0].replace("- ", " + -")
if snd_part_is_good:
    tab[1] = tab[1].replace("- ", " + -")

part1 = [i.replace("--", "").strip() for i in re.split(r'(?: \+ )', tab[0])]
if snd_part_is_good:
    part2 = [i.replace("--", "").strip() for i in re.split(r'(?: \+ )', tab[1])]

left = {}

for i in part1:
    l, j = process_input(i)
    left[j] = l

if snd_part_is_good:
    for i in part2:
        l, j = process_input(i)
        if j in left:
            left[j] -= l
        else:
            left[j] = -l;

print("Reduced form: ", end="")
ok = 0
for i in left:
    if left[i] >= 0:
        if ok:
            print (" + ", end="")
        print (str(left[i]) + " * X^" + str(i), end="")
    else:
        if ok:
            print (" - ", end="")
        else:
            print("-", end="")
        print (str(-left[i]) + " * X^" + str(i), end="")
    ok = 1

print(" = 0")

max_key = next(iter(left))
for i in left:
    if left[i] != 0:
        max_key = max(max_key, i)

print("Polynomial degree:", max_key)

if max_key == 1 and left[max_key] != 0:
    print ("The soultion is:")
    if 0 in left:
        print (float(-left[0]) / left[1])
    else:
        print (0)
elif max_key == 2 and left[max_key] != 0:
    a = left[2]
    b = left[1] if 1 in left else 0
    c = left[0] if 0 in left else 0
    disc = b * b - 4 * a * c
    if disc > 0:
        print ("Discriminant is strictly positive, the two solutions are:")
        print_rsolution((-b + sqrt(disc)) / (2 * a))
        print_rsolution((-b - sqrt(disc)) / (2 * a))
    elif disc == 0:
        print ("Discriminant is equal to zero. The only solution is:")
        print_rsolution(-b / (2 * a))
    else:
        print ("Discriminant is strictly negative, the two complex solutions are:")
        print_csolution(complex(-b / (2 * a), sqrt(-disc) / (2 * a)))
        print_csolution(complex(-b / (2 * a), -sqrt(-disc) / (2 * a)))
elif max_key > 2 and left[max_key] != 0:
    print ("The polynomial degree is stricly greater than 2, I can't solve.")
else:
    if left[max_key] == 0:
        print ("Any real number can be the solution")
    else:
        print ("There aren't any solutions to the equation")
