# https://codefights.com/challenge/GPw6LZT685xxJgnvT/main

def GenerateCode(label, year, model, number):
    length = len(label) + 3 #This is the length not including length of the number
    output_string = ""
    output_string += label  #No change to label. It will be appended as it is.
    length_of_year = len(str(year))
    year_as_string = str(year)
    if(length_of_year < 2):
        output_string = output_string + '0' + year_as_string
    elif(length_of_year < 3):
        output_string += year_as_string
    else:
        output_string = output_string + year_as_string[length_of_year -2:]
    output_string += (chr(model + 64)) #ASCII convert
    length_of_number = len(str(number))
    number_as_string = str(number)
    if((length + length_of_number) == 9):
        output_string += number_as_string
    elif((length + length_of_number) > 9):
        output_string += number_as_string[length - 9:]
    else:
        output_string += ('0' * (9 - (length_of_number + length)))
        output_string += number_as_string

    return output_string

print(GenerateCode("B",2015,3,678))


