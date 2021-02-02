import json
from difflib import get_close_matches

data = json.load(open("data.json"))

def meaning(w):
    w = w.lower()

    if w in data:
        return data[w]
    elif w.title() in data:
        return data[w.title()]
    elif w.upper() in data: 
        return data[w.upper()]
    elif len(get_close_matches(w, data.keys())) > 0:
        yn = input("Did you mean '%s' instead?\nEnter Y if yes, or N if no: " % get_close_matches(w, data.keys())[0])
        if yn == "Y" or yn == 'y':
            return data[get_close_matches(w, data.keys())[0]]
        elif yn == "N" or yn == 'n':
            return "The word doesn't exist. Please check it again."
        else:
            return "We didn't understand your entry."
    else:
        return "The word doesn't exist. Please check it again."

word = input("\nEnter word: ")
output = meaning(word)

if type(output) == list:
    i = 1
    for item in output:
        print('\n{}. {}'.format(i, item))
        i += 1
else:
    print(output)