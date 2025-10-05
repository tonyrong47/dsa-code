#stack(finding greater number)
#In an array of integers,finding the next greater element using Stack
#if no greater element exists,put -1(on the output)

def nextGreaterElements(arr):
    n=len(arr)
    result=[-1]*n
    stack=[]

    for i in range(n):
        while stack and arr[i]>arr[stack[-1]]:
            idx=stack.pop()
            result[idx]=arr[i]
        stack.append(i)
    
    return result

#sample(To test the function you can uncomment the comments)
#arr=[3,5,8,21]
#print(nextGreaterElements(arr))