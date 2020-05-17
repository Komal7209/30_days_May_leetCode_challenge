class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> _mag;

        for (char c : magazine)
        {
            if (_mag.find(c) != _mag.end())
            {
                int count = _mag[c] + 1;
                _mag[c] = count;
            }
            else
                _mag.insert({c, 1});
        }

        for (char c : ransomNote)
        {
            if (_mag.find(c) == _mag.end())
                return false;
            int count = _mag[c];
            if (count == 0)
                return false;
            _mag[c] = count - 1;
        }

        return true;
    }
};