def InfixtoPostfix(exp):
    #code here
    prec={
        "^":1,
        "+":3,"-":3,
        "*":2,"/":2
    }
    ans=""
    stack=[]
    for i in range(len(exp)):
        if exp[i]=="(":
            stack.append("(")
        elif exp[i]==")":
            while(stack):
                p=stack.pop()
                if p=="(":
                    break
                else:
                    ans+=p
        elif exp[i] in prec:            
            if (not stack) or stack[-1]=="(" or (prec[exp[i]]<prec[stack[-1]]):
                stack.append(exp[i])
            elif prec[exp[i]]>=prec[stack[-1]]:
                while(stack):
                    if stack[-1]=="(" or prec[exp[i]]<prec[stack[-1]] :
                        break
                    ans+=stack.pop()
                stack.append(exp[i]) 
        else:
            ans+=exp[i]
    while(stack):
        ans+=stack.pop()
    return ans    


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        exp = str(input())
        print(InfixtoPostfix(exp))