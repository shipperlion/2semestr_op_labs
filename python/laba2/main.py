import module

name = input("Enter the name of file(name.bin): ")  # entry of the name of file
module.create_file(name)       # call of function to create list
print("\nList of served clients:")      # output of list
module.output_file(name)
newname = "blacklist.bin"      # file with clients served more than 30 minutes
module.black_list(name, newname)       # call of function to create this file
print("\nBlack list:")
module.output_file(newname)     # output of rhis file
