class Solution {
public:
    
static bool compareByLength(const string& a, const string& b)
{
	return a.size() > b.size();
}


int minimumLengthEncoding(vector<string>& words2) {

    sort(words2.begin(), words2.end());
    
    vector<string> words;
    
    words.push_back(words2[0]);
    
    for(int i=1 ; i < words2.size(); i++)
    {
        if(words2[i-1].compare(words2[i]) != 0)
            words.push_back(words2[i]);
    }
    
    
	sort(words.begin(), words.end(), compareByLength);

	// for (string x : words)
	// 	cout << x << "\t";

	vector<string>::reverse_iterator itr;
	itr = words.rbegin();
	bool erased = false;

	while (itr != words.rend())
	{
		for (int i = 0; i < words.size(); i++)
		{
			if (words[i].size() > itr->size() && (words[i].compare((words[i].size() - itr->size()), itr->size(), *itr) == 0))
			{
				words.erase(--itr.base());
				erased = true;
				break;
			}

		}

		if (!erased)
			itr++;
		else
			itr = words.rbegin();
        
        erased = false;
	}
	int sizet = 0;
	for (string x : words)
		sizet += x.size() + 1;
	return sizet;
}    
};
