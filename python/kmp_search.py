def make_lps(P):
    M = len(P)
    lps = [0] * M
    length = 0
    i = 1

    while i < M:
        if P[i] == P[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    return lps

def kmp_find(T, P):
    N = len(T)
    M = len(P)
    
    if M == 0:
        return []
    
    lps = make_lps(P)
    
    i = 0
    j = 0
    occs = []

    while i < N:
        if P[j] == T[i]:
            i += 1
            j += 1

        if j == M:
            occs.append(i - j)
            j = lps[j - 1] 

        elif i < N and P[j] != T[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
                
    return occs

# Example
text_str = "ABABDABACDABABCABAB"
pat = "ABABCABAB"
result = kmp_find(text_str, pat)

print(f"Pattern found at: {result}")