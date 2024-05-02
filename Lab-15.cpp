#include <iostream>
#include <vector>
#include <string>
// You'll need a dictionary library/API to check if a word is valid English
// [Optional] Implement a function to check if a word is valid English yourself using a trie or a hash table.

bool is_substring(const std::string &word, const std::string &substring)
{
    int n = word.length(), m = substring.length();
    if (m > n)
    {
        return false;
    }
    for (int i = 0; i <= n - m; i++)
    {
        bool match = true;
        for (int j = 0; j < m; j++)
        {
            if (word[i + j] != substring[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            return true;
        }
    }
    return false;
}

// Function to generate all substrings of length k in a string
void generate_substrings(const std::string &word, int k, std::vector<std::string> &substrings)
{
    if (k == 1)
    {
        for (char c : word)
        {
            substrings.push_back(std::string(1, c));
        }
        return;
    }

    // Generate substrings of length k-1
    std::vector<std::string> temp_substrings;
    generate_substrings(word, k - 1, temp_substrings);

    // Append the current character to each substring of length k-1 to get substrings of length k
    for (const std::string &substring : temp_substrings)
    {
        for (char c : word)
        {
            substrings.push_back(substring + c);
        }
    }
}

int main()
{
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word;

    for (int k = 1; k <= word.length(); k++)
    {
        std::vector<std::string> substrings;
        generate_substrings(word, k, substrings);

        for (const std::string &substring : substrings)
        {
            if (substring.length() <= 4)
            {
                std::cout << "Shortest valid variant found: " << substring << std::endl;
                return 0;
            }
        }
    }

    std::cout << "No shorter variant found." << std::endl;

    return 0;
}
