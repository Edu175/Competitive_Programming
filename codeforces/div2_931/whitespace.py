s=open(0).read()
l="exec(''.join(chr(len(e)) for e in '"
r="'.split('	')))"
for i in range(len(s)):
	if i:
		l+="	"
	l+=' '*ord(s[i])
print(l+r)
