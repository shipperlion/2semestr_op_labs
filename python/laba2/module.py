def create_file(name):      # function to fill the list with clients
    frecord = open(name, "ab")      # opening of file to append
    print("Input of data.........")
    client = ["", "", ""]   # lists to save here data of clients
    temp = ["", "", ""]
    client[0] = input("Surname: ")  # input of surname
    client[1] = input("Start time(hh:mm): ")    # input of start time of previous client
    client[2] = input("End time(hh:mm): ")      # input of end time of previous client
    string = client[0] + "\t" + client[1] + " - " + client[2] + "\r\n"  # concatenation
    finstr = string.encode()    # encoding the string
    frecord.write(finstr)   # writing string in file
    flag = input("Continue? (Y/N)")
    while flag == "Y" or flag == "y":
        clhour = int(client[2][0:2])    # hours of end time of previous client
        clmin = int(client[2][3:])      # minutes of end time of previous client
        temp[0] = input("Surname: ")    # input of surname
        temp[1] = input("Start time(hh:mm): ")  # input of start time of current client
        temp[2] = input("End time(hh:mm): ")    # input of end time of current client
        thour = int(temp[1][0:2])   # hours of start time of current client
        tmin = int(temp[1][3:])     # minutes of start time of current client
        while clhour*60 + clmin > thour*60 + tmin:  # conversion to minutes and comparison
            print("Visiting times overlap. Please, try again")
            temp[1] = input("Start time(hh:mm): ")  # re-input of start time of current client
            temp[2] = input("End time(hh:mm): ")    # re-input of end time of current client
            thour = int(temp[1][0:2])   # hours of start time of current client
            tmin = int(temp[1][3:])     # minutes of start time of current client
        string = temp[0] + "\t" + temp[1] + " - " + temp[2] + "\r\n"    # concatenation
        finstr = string.encode()    # encoding the string
        frecord.write(finstr)       # writing string in file
        client = [temp[0], temp[1], temp[2]]    # turning current client into previous
        flag = input("Continue? (Y/N)")
    frecord.close()     # closing the file


def black_list(name1, name2):   # function to create list with clients served more than 30 min
    frecord = open(name2, "wb")     # opening of file to write
    fread = open(name1, "rb")       # opening of file to read
    served = fread.read()   # reading all text from file
    text = served.decode()  # decoding text
    split = text.split("\r\n")  # splitting text into lines
    for line in split:      # line enumeration
        if line != '':      # checking line for emptiness
            pos = line.find(":")    # position of first ":"
            rpos = line.rfind(":")  # position of last ":"
            shour = int(line[pos - 2:pos])  # hours of start time
            smin = int(line[pos + 1:pos + 3])   # minutes of start time
            ehour = int(line[rpos - 2:rpos])    # hours of end time
            emin = int(line[rpos + 1:rpos + 3])     # minutes of end time
            if (ehour * 60 + emin) - (shour * 60 + smin) > 30:  # conversion to minutes and comparison
                newline = line + "\r\n"     # adding the transition to a new line
                finstr = newline.encode()   # encoding the string
                frecord.write(finstr)   # writing to the file
    fread.close()   # closing files
    frecord.close()


def output_file(name):  # function to output the files
    fread = open(name, "rb")    # opening the file to read
    for line in fread:  # reading lines
        s = line.decode()   # decoding the line
        s = s[:-1]  # omitting the last character
        print(s)    # output of file
    fread.close()   # closing the file
