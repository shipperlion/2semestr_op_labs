def create_file(name):          # Function to create file and record
    frecord = open(name, "wt")  # the text in it
    print("Enter the text:")
    string = ""
    text = ""
    while string != "end":      # End-checking
        string = input()
        if string == "end":
            break
        text += string + '\n'
    print(text, file=frecord, sep='', end='')
    frecord.close()             # Closing file


def output_file(name):          # Function to output file
    fread = open(name, "rt")    # Opening file
    flag = True
    print("Content of file:")
    while flag:                 # End-checking
        file_text = fread.read()
        if not file_text:
            flag = False
        else:
            print(file_text)


def new_file(name1, name2, name3):
    fread1 = open(name1, "rt")  # Opening files
    fread2 = open(name2, "rt")
    frecord = open(name3, "wt")
    number = -1                 # Number of identical
    file1 = fread1.read()       # Copying text of files in
    file2 = fread2.read()       # variables
    file1split = file1.split("\n")
    file2split = file2.split("\n")
    for string1 in file1split:  # Searching for identical
        for string2 in file2split:
            if string1 == string2:
                print(string1 + '\n', file=frecord, sep='', end='')
                number += 1
    print("Number of identical strings in files: ", number)
    fread1.close()              # Closing files
    fread2.close()
    frecord.close()


name1 = "text1.txt"     # First file
name2 = "text2.txt"     # Second file
result = "result.txt"   # Result file
create_file(name1)      # Creating files
create_file(name2)      # Creating second file
new_file(name1, name2, result)
output_file(name1)      # Outputing files
output_file(name2)
output_file(result)
