class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        vowel = ['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U']
        tmp = S.split(' ')
        record = []
        count = 1
        for word in tmp:
            print (word)
            if word[0] in vowel:
                curr = word +'ma' + 'a' * count
            else:
                curr = word[1:] + word[0] + 'ma' + 'a' * count
            count += 1
            print(curr)
            record.append(curr)
        return str.join(' ', record)
            
        