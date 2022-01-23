# simple string test

initial purpose was just to prove that something like

```C++

void foo(char *s, size_t length) {
	char source[] = "Hello World";

	strncpy(s, length source, sizeof(source));
}


std::string s;
s.reserve(512);
foo(&s[0], sizeof(char) * 512);
```

this isn't the exact code I used but the general idea - passing the start of the string buffer 
to a C function that copies to it directly, some sources would say this would work and technically
it can with one major caveat - the buffer will be updated but the ```std::string``` length will
remain at 0 