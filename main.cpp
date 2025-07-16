// main.cpp : Bu dosya 'main' iþlevi içeriyor. Program yürütme orada baþlayýp biter.
//
/*MIT License

Copyright (c) 2025 Osderda

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/
#include <iostream>
#include <windows.h> 
#include <vector>
#include <string>
/*13. Longest Common Prefix*/
namespace p2{

    struct words{
        size_t countWord;
        std::string word;
    };
    std::string calc(std::vector<std::string>& array, bool checkSames=false) {
        std::vector<std::string> finishStr{ };
        std::vector<words> finishWord;
        int cacheCount = 0;
        BYTE finish = 1;
        BYTE found = 1;
        int araySize = array.size(); ;
        while (finish)
        {
            if (araySize <= cacheCount)
            {
                finish = false;
                continue;
            }
            std::string cache = array[cacheCount];
            int curLeng = array[cacheCount].length();
            int nextNum = 0;
            for (auto nextStr : array) { 
                if (nextNum  < cacheCount && array[araySize - 1] == nextStr)
                {
                    nextNum++;
                    continue;
                }
                std::string outCur{ };
                std::string nextCache = nextStr;
         
                if ( !checkSames && nextCache == cache && array[araySize-1]!= nextCache)
                    continue;
                byte addCache = 0;
                for (size_t i = 0; i < curLeng; i++)
                {
                    if (i >= nextCache.length())
                        break;

                    if (cache[i] == nextCache[i])
                    { 
                            addCache = 1;
                            outCur += cache[i];
                       
                    }
                    else if (i > 0) break;
                }
                if (addCache)
                    finishStr.push_back(outCur);

            }
            cacheCount++;
        } 
        std::string out; 
        for (size_t i = 0; i < finishStr.size(); i++)
        {
            int araySize = finishStr.size();
            if (araySize <= i)
            { 
                finish = false;
                break;
            }
            auto cur = finishStr[i];
            if (araySize<2)
            {
                out = cur;
            }
            byte alredyHaved = 0;
            for (size_t wordww = 0; wordww < finishWord.size(); wordww++)
            {
                auto curword = finishWord[wordww];

                if (curword.word == cur)
                {
                    curword.countWord++;
                    alredyHaved = 1;
                }
                finishWord[wordww]= curword;
            } 
            if (alredyHaved)
            {
                continue;
            }
            words curWord;
            curWord.countWord = 0;
            for (size_t e = 1; e < finishStr.size(); e++)
            {

                auto next = finishStr[e ];

                if (cur == next)
                {
                    curWord.countWord++;
                    curWord.word = cur;
                }
            }
            finishWord.push_back(curWord);
            found++;
        }

        for (auto wordm : finishWord)
        {
            static int lastbig = 0;
            if (wordm.countWord > lastbig && lastbig ==0)
            {
                lastbig = wordm.countWord;
                out = wordm.word;
            }
        }
        return out;
    }
  
	bool run() {
        std::vector<std::string> input = { "rowmap","rowser","rowcak","awwrowbbb","awwrowdes"};
        printf("IN t = { rowmap,rowser,rowcak,awwrowbbb,awwrowdes}\n");
        printf("Out -> %s\n", calc(input).c_str());
      
        return true;
	}

}
int main()
{ 
    p2::run();
    system("pause");
}
