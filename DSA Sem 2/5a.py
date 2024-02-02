with open("text1.txt", "r") as f:
    data = f.read()

with open("text2.txt", "w") as f:
    f.write(data.upper())

