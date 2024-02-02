def addEmp(emp):
    while True:
        records={}
        name=input("Enter name of Employee: ")
        id=int(input("Enter id of Employee: "))
        salary=int(input("Enter salary of Employee: "))
        city=input("Enter the city Employee lives in: ")
        records['Name']=name
        records['ID']=id
        records['Salary']=salary
        records['City']=city
        emp.append(records)
        ans=input("Do you want to enter more records[n to exit]")
        print("\n")
        if ans.lower()=='n':
            break

def modifyEmp(emp):
    if len(emp)!=0:
        index=int(input("Enter index of required Employee: "))
        if index>len(emp):
            print("Enter valid value!\n")
        else:
            print(emp[index-1])
            while True:
                print("\n")
                print("Choose the value to be changed[Name/ID/Salary/City]:")
                choice2=input()
                if choice2=='Name':
                    emp[index-1]['Name']=input("Enter new Name: ")
                    print("\n")
                    break
                elif choice2=='ID':
                    emp[index-1]['ID']=int(input("Enter new ID: "))
                    print("\n")
                    break
                elif choice2=='Salary':
                    emp[index-1]['Salary']=int(input("Enter new Salary: "))
                    print("\n")
                    break
                elif choice2=='City':
                    emp[index-1]['City']=input("Enter new City: ")
                    print("\n")
                    break
                else:
                    print("Enter valid value!")
                    print("\n")
    else:
        print("Empty Records!")

def displayEmp(emp):
    if len(emp)!=0:
        for i in range(len(emp)):
            print(emp[i])
            print("\n")
    else:
        print("Empty Records!\n")
emp=[]
while True:
    print("Choose Operation:\n1.Add employee\n2.Modify Data\n3.Display Records\n4 Exit\n------------------")
    choice=input()
    if choice=='1':
        addEmp(emp)
    elif choice=='2':
        modifyEmp(emp)
    elif choice=='3':
        displayEmp(emp)
    elif choice=='4':
        print("Exiting...")
        break
    else:
        print("Enter valid Value!")



