def compute_lps_array(pat):
    lps = [0] * len(pat)
    length = 0
    i = 1

    while i < len(pat):
        if pat[i] == pat[length]:
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

def kmp_search(pat, txt):
    M = len(pat)
    N = len(txt)

    lps = compute_lps_array(pat)

    i = 0  # Index for txt
    j = 0  # Index for pat

    while i < N:
        if pat[j] == txt[i]:
            i += 1
            j += 1

        if j == M:
            print(f"Pattern found at index {i - j}")
            j = lps[j - 1]

        elif i < N and pat[j] != txt[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
