# Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

# A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
def letterCombinations(digits):
    """
    :type digits: str
    :rtype: List[str]
    """
    #here we use back tracking approach


    if digits=="":
        return []
    else:
        
        st=""
        dic={
            2:"abc",
            3:"def",
            4:"ghi",
            5:"jkl",
            6:"mno",
            7:"pqrs",
            8:"tuv",
            9:"wxyz"
        }
        # for i in digits:
        #     st+=dic[int(i)]
    li=[]

    #this function will give combinations of letters
    def combi(comb,start):
        if len(comb)==len(digits):
            li.append("".join(comb))
            return
        
        curdig=digits[start]
        letters=dic[int(curdig)]
        for l in letters:
            
            #add letter to comb and call function for next digit
            comb.append(l)
            combi(comb,start+1)
            #after returning remove the letter from comb to make it ready for next letter
            comb.pop()
        


        

    combi([],0)

    return li
