with open("text1.txt", "r") as f:
    data = f.read()

no_of_words = data.count(" ") + 1

print(no_of_words)