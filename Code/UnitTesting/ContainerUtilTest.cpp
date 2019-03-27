#include "stdafx.h"
#include "CppUnitTest.h"
#include "ContainerUtil.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(ContainerUtilTest)
	{
	public:

		TEST_METHOD(intVecToMapVec_empty_success)
		{
			std::vector<int> emptyIntVec;
			std::string key ("key");
			std::unordered_map<std::string, std::vector<std::string>> result = ContainerUtil::to_mapvec(key, 
				emptyIntVec);
			std::unordered_map<std::string, std::vector<std::string>> toCompare;
			std::vector<std::string> emptyVec;
			std::pair<std::string, std::vector<std::string>> keyValuePair (key, emptyVec);
			toCompare.insert(keyValuePair);

			Assert::AreEqual(result == toCompare, true);
		}
		TEST_METHOD(intVecToStrSet_nonEmpty_success)
		{
			std::vector<int> nonEmptyIntVec { 1, 2, 3 };
			std::string key ("key");
			std::unordered_map<std::string, std::vector<std::string>> result = ContainerUtil::to_mapvec(key,
				nonEmptyIntVec);
			std::unordered_map<std::string, std::vector<std::string>> toCompare;
			std::vector<std::string> vec { "1", "2", "3" };
			std::pair<std::string, std::vector<std::string>> keyValuePair (key, vec);
			toCompare.insert(keyValuePair);

			Assert::AreEqual(result == toCompare, true);
		}

		TEST_METHOD(intStrVecToStrSet_empty_success)
		{
			std::vector<std::pair<int, std::string>> emptyIntStrVec;
			std::string key1 ("key1");
			std::string key2 ("key2");
			std::unordered_map<std::string, std::vector<std::string>> result = ContainerUtil::to_mapvec(key1, 
				key2, emptyIntStrVec);
			std::unordered_map<std::string, std::vector<std::string>> toCompare;
			std::vector<std::string> emptyVec;
			std::pair<std::string, std::vector<std::string>> keyValuePair1 (key1, emptyVec);
			std::pair<std::string, std::vector<std::string>> keyValuePair2 (key2, emptyVec);
			toCompare.insert(keyValuePair1);
			toCompare.insert(keyValuePair2);
			Assert::AreEqual(result == toCompare, true);
		}

		TEST_METHOD(intStrVecToStrSet_nonEmpty_success)
		{
			std::vector<std::pair<int, std::string>> nonEmptyIntStrVec;
		    std::pair<int, std::string> firstPair (1, "one");
			std::pair<int, string> secondPair (2, "two");
			nonEmptyIntStrVec.push_back(firstPair);
			nonEmptyIntStrVec.push_back(secondPair);
			std::string key1 ("key1");
			std::string key2 ("key2");
			std::unordered_map<std::string, std::vector<string>> result = ContainerUtil::to_mapvec(key1,
				key2, nonEmptyIntStrVec);
			std::unordered_map<std::string, std::vector<string>> toCompare;
			std::vector<std::string> vec1 { "1", "2" };
			std::vector<std::string> vec2 { "one", "two" };
			std::pair<std::string, std::vector<std::string>> keyValuePair1 (key1, vec1);
			std::pair<std::string, std::vector<std::string>> keyValuePair2 (key2, vec2);
			toCompare.insert(keyValuePair1);
			toCompare.insert(keyValuePair2);
			Assert::AreEqual(result == toCompare, true);
		}

		TEST_METHOD(intSetToStrSet_empty_success)
		{
			std::unordered_set<int> emptyIntSet;
			std::string key ("key");
			std::unordered_map<std::string, std::vector<string>> result = ContainerUtil::to_mapvec(key,
				emptyIntSet);
			std::unordered_map<std::string, std::vector<string>> toCompare;
			std::vector<std::string> emptyVec;
			std::pair<std::string, std::vector<std::string>> keyValuePair (key, emptyVec);
			Assert::AreEqual(result == toCompare, true);
		}

		TEST_METHOD(inSetToStrSet_nonEmpty_success)
		{
			std::unordered_set<int> nonEmptyIntSet ({ 1, 2, 3 });
			std::string key ("key");
			std::unordered_map<std::string, std::vector<string>> result = ContainerUtil::to_mapvec(key, 
				nonEmptyIntSet);
			Assert::AreEqual(result.count(key) == 1, true);
			std::vector<std::string> toCheck = result[key];
			for (vector<std::string>::size_type i = 0; i != toCheck.size(); i++) {
				Assert::AreEqual(nonEmptyIntSet.count(stoi(toCheck[i])) == 1, true);
			}
		}

		TEST_METHOD(intPairSetToStrSet_empty_success)
		{
			std::unordered_set<pair<int, int>, intPairhash> emptyIntPairSet;
			std::string key1 ("key1");
			std::string key2 ("key2");
			std::unordered_map<std::string, std::vector<string>> result = ContainerUtil::to_mapvec(key1,
				key2, emptyIntPairSet);
			std::unordered_map<std::string, std::vector<string>> toCompare;
			std::vector<std::string> emptyVec;
			std::pair<std::string, std::vector<std::string>> keyValuePair1 (key1, emptyVec);
			std::pair<std::string, std::vector<std::string>> keyValuePair2 (key2, emptyVec);
			toCompare.insert(keyValuePair1);
			toCompare.insert(keyValuePair1);
			Assert::AreEqual(result == toCompare, true);
		}

		TEST_METHOD(intPairSetToStrSet_nonEmpty_success)
		{
			std::unordered_set<std::pair<int, int>, intPairhash> nonEmptyIntPairSet;
			std::pair<int, int> firstPair(1, 2);
			std::pair<int, int> secondPair(3, 4);
			nonEmptyIntPairSet.insert(firstPair);
			nonEmptyIntPairSet.insert(secondPair);
			std::string key1 ("key1");
			std::string key2 ("key2");
			std::unordered_map<std::string, std::vector<std::string>> result = ContainerUtil::to_mapvec(key1,
				key2, nonEmptyIntPairSet);
			Assert::AreEqual(result.count(key1) == 1, true);
			Assert::AreEqual(result.count(key2) == 1, true);
			std::vector<std::string> toCheck1 = result[key1];
			std::vector<std::string> toCheck2 = result[key2];
			for (vector<std::string>::size_type i = 0; i != toCheck1.size(); i++) {
				int firstOfPair = stoi(toCheck1[i]);
				int secondOfPair = stoi(toCheck2[i]);
				std::pair<int, int> currentPair (firstOfPair, secondOfPair);
				Assert::AreEqual(nonEmptyIntPairSet.count(currentPair) == 1, true);
			}
		}

		TEST_METHOD(intStrSetToStrSet_empty_success)
		{
			std::unordered_set<std::pair<int, std::string>, intStringhash> emptyIntStrSet;
			std::string key1 ("key1");
			std::string key2 ("key2");
			std::unordered_map<std::string, std::vector<string>> result = ContainerUtil::to_mapvec(key1,
				key2, emptyIntStrSet);
			std::unordered_map<std::string, std::vector<string>> toCompare;
			std::vector<std::string> emptyVec;
			std::pair<std::string, std::vector<std::string>> keyValuePair1(key1, emptyVec);
			std::pair<std::string, std::vector<std::string>> keyValuePair2(key2, emptyVec);
			toCompare.insert(keyValuePair1);
			toCompare.insert(keyValuePair1);
			Assert::AreEqual(result == toCompare, true);
		}

		TEST_METHOD(intStrSetToStrSet_nonEmpty_success)
		{
			std::unordered_set<std::pair<int, string>, intStringhash> nonEmptyIntStringSet;
			std::pair<int, string> firstPair (1, "baby");
			std::pair<int, string> secondPair (2, "shark");
			nonEmptyIntStringSet.insert(firstPair);
			nonEmptyIntStringSet.insert(secondPair);
			std::string key1 ("key1");
			std::string key2 ("key2");
			std::unordered_map<std::string, std::vector<std::string>> result = ContainerUtil::to_mapvec(key1,
				key2, nonEmptyIntStringSet);
			Assert::AreEqual(result.count(key1) == 1, true);
			Assert::AreEqual(result.count(key2) == 1, true);
			std::vector<std::string> toCheck1 = result[key1];
			std::vector<std::string> toCheck2 = result[key2];
			for (vector<std::string>::size_type i = 0; i != toCheck1.size(); i++) {
				int firstOfPair = stoi(toCheck1[i]);
				std::string secondOfPair = toCheck2[i];
				std::pair<int, std::string> currentPair(firstOfPair, secondOfPair);
				Assert::AreEqual(nonEmptyIntStringSet.count(currentPair) == 1, true);
			}
		}

		TEST_METHOD(strPairSetToStrSet_empty_success)
		{
			std::unordered_set<std::pair<std::string, std::string>, strPairhash> emptyStrPairSet;
			std::string key1 ("key1");
			std::string key2 ("key2");
			std::unordered_map<std::string, std::vector<string>> result = ContainerUtil::to_mapvec(key1,
				key2, emptyStrPairSet);
			std::unordered_map<std::string, std::vector<string>> toCompare;
			std::vector<std::string> emptyVec;
			std::pair<std::string, std::vector<std::string>> keyValuePair1(key1, emptyVec);
			std::pair<std::string, std::vector<std::string>> keyValuePair2(key2, emptyVec);
			toCompare.insert(keyValuePair1);
			toCompare.insert(keyValuePair1);
			Assert::AreEqual(result == toCompare, true);
		}

		TEST_METHOD(strPairSetToStrSet_nonEmpty_success)
		{
			std::unordered_set<std::pair<string, string>, strPairhash> nonEmptyStrPairSet;
			std::pair<string, string> firstPair("baby", "shark");
			std::pair<string, string> secondPair("telling", "lies");
			nonEmptyStrPairSet.insert(firstPair);
			nonEmptyStrPairSet.insert(secondPair);
			std::string key1("key1");
			std::string key2("key2");
			std::unordered_map<std::string, std::vector<std::string>> result = ContainerUtil::to_mapvec(key1,
				key2, nonEmptyStrPairSet);
			Assert::AreEqual(result.count(key1) == 1, true);
			Assert::AreEqual(result.count(key2) == 1, true);
			std::vector<std::string> toCheck1 = result[key1];
			std::vector<std::string> toCheck2 = result[key2];
			for (vector<std::string>::size_type i = 0; i != toCheck1.size(); i++) {
				std::string firstOfPair = toCheck1[i];
				std::string secondOfPair = toCheck2[i];
				std::pair<std::string, std::string> currentPair(firstOfPair, secondOfPair);
				Assert::AreEqual(nonEmptyStrPairSet.count(currentPair) == 1, true);
			}
		}
	};
}