'''
Let the three subjects be Maths, Physics and Computers
with Max marks equal to 100
'''
while True:
    maths=int(input("Enter the marks in Maths: "))
    physics=int(input("Enter the marks in Physics: "))
    computers=int(input("Enter the marks in Computers: "))
    if(maths>100 or physics>100 or computers>100):
        print("Marks cannot be greater than 100!")
    elif(maths<0 or physics<0 or computers<0):
        print("Marks cannot be less than 0!")
    else:
        break
print(f"The percentage scored is {(maths+physics+computers)/3}")