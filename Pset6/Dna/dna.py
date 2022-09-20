from sys import argv
import csv
from sys import exit
import re


if (len(argv) != 3) :
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)
    

strands = []
people = {}
with open(argv[1] , 'r') as file:
    for index , row in enumerate(file): #enumerate so we can count the number of lines
        if index == 0 :
            strands = [strand for strand in row.strip().split(',')][1:] #for the first line strip the commas
        else:
            cursor = row.strip().split(',') #cursor is the stripped from the \n and commas
            people[cursor[0]] = [int (x) for x in cursor[1:]]
#print(strands)
#print(people)

dna_strand = open(argv[2] , 'r').read()

final_count = []

for strand in strands:
    max_c = 0
    maximum = -1
    i = 0
   
    while i < len(dna_strand):
        current = dna_strand[i: i + len(strand)]#read a string as long as the strand
        if current == strand:
            max_c += 1
            i += len(strand)
            maximum = max(maximum , max_c)
        else:
            i += 1
            max_c = 0
    final_count.append(maximum) 
for name , numbers in people.items(): #.items so we can select the items 
    if numbers == final_count:
        print(name)
        exit()
print("No match")