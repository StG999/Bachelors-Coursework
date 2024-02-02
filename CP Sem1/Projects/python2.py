even=filter(lambda x:x%2==0,range(11))
cubes=list(map(lambda x:x*x*x,even))
sum=0
for i in cubes:
    sum+=i
print(f"The sum of cubes of first 5 even numbers is {sum}")