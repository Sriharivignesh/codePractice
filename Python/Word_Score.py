def WordScore(word):
    score = 0
    for c in word:
        score+=ord(c)-96
    return score

print(WordScore("lazy"))