/*
 * Name : Govind Sahai
 * Roll : 13123006
 * Branch : 5th yr MnC
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int letterValue(char ch)
{
	int value = 0; 

	switch(ch)
	{
		case 'A': case 'a': 
		case 'E': case 'e':  
		case 'I': case 'i': 
		case 'L': case 'l':
		case 'N': case 'n':
		case 'O': case 'o': 
		case 'R': case 'r': 
		case 'S': case 's': 
		case 'T': case 't': 
		case 'U': case 'u': 
			value += 1; break; 
		case 'D': case 'd': 
		case 'G': case 'g': 
			value += 2; break; 
		case 'B': case 'b': 
		case 'C': case 'c': 
		case 'M': case 'm':  
		case 'P': case 'p': 
			value += 3; break; 
		case 'F': case 'f': 
		case 'H': case 'h': 
		case 'V': case 'v': 
		case 'W': case 'w': 
		case 'Y': case 'y': 
			value += 4; break; 
		case 'K': case 'k': 
			value += 5; break; 
		case 'J': case 'j': 
		case 'X': case 'x': 
			value += 8; break; 
		case 'Q': case 'q':
		case 'Z': case 'z': 
			value += 10; break; 
	}
	return value; 
}

size_t stringValue(string s)
{
	size_t scr = 0;
	for(auto x : s)
		scr += letterValue(x);
	return scr;
}

int main(int argc, char* argv[])
{

	string df, wf, cf = "characters.txt";
	if(argc != 2)
	{
		cout << argv[0] << " [1 for small, 2 for large]";
		return 0;
	}
	if(stoll(argv[1]) == 1)
	{
		df = "dictionary_min.txt";
		wf = "words_min.txt";
	}
	else
	{
		df = "dictionary.txt";
		wf = "words.txt";
	}

	ifstream fdict(df);
	string wordx;
	unordered_set<string> st, wd;
	while(getline(fdict, wordx))
	{
		st.insert(wordx);
	}
	fdict.close();
	ifstream fword(wf);

	while(getline(fword, wordx))
	{
		bool yes =	(wordx.length() >= 2) and (wordx.length() <= 15) and (st.find(wordx) != st.end());
		if(yes)
			wd.insert(wordx);
	}
	fword.close();

	ll num = 0;

	vector<int> vcx = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1};

	ifstream fchar(cf);
	string chars;
	fchar >> chars;

	string pw = "0";

	for(int i_ = 0; i_ < chars.size() - 6; i_ += 7)
	{
		string ss = chars.substr(i_, 7);
		pair<string, ll> mx = {"", 0};
		int cnt[200] = {0};
		for(auto& x : vcx) x = 0;
		for(auto& x : ss) vcx[x - 'a']++;
		for(auto x_ : pw)
		{
			auto& vc = vcx;
			for(auto& word : wd)
			{
				for(auto& x : cnt) x = 0;
				for(auto& x : word) cnt[tolower(x)]++;

				ll blank = 0;
				ll score = 0;
				bool yes = true;
				for(int i = 'a'; i <= 'z' and yes; ++i)
				{
					score += min(cnt[i], vc[i - 'a']) * letterValue(i);
					if(cnt[i] > vc[i - 'a'])
					{
						if(cnt[i] == vc[i - 'a'] + 1)
						{
							blank--;
						}
						else if(cnt[i] == vc[i - 'a'] + 2)
						{
							blank -= 2;
						}
						else
							yes = false;
					}
					if(blank < 0)
						yes = false;
				}

				if(!yes)
					continue;
				if(pw != "0")
					cout << word << endl;

				num++;

				if(score > mx.second)
					mx = {word, score};
			}
		}
		cout << endl;
		cout << "Deck : " << ss << endl;
		cout << "Total no of valid words : " << num << endl;

		if(mx.second == 0)
			cout << "No word found!!" << endl;
		else
			cout << "Word with max score : " << mx.first << " :: Score : " << mx.second << endl;

	}

	return 0;
}
