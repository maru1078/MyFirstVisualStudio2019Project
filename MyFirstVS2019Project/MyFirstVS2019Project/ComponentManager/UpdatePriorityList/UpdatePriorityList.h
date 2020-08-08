#ifndef UPDATE_PRIORITY_LIST_H_
#define UPDATE_PRIORITY_LIST_H_

#include <unordered_map>
#include <typeindex>
#include <memory>

class UpdatePriorityList
{
public:

	template<class T>
	void AddPriority(float priority);

	template<class T>
	float GetUpdatePriority() const;

private:

	std::unordered_map<std::type_index, float> m_priorityMap;
};

template<class T>
inline void UpdatePriorityList::AddPriority(float priority)
{
	m_priorityMap.emplace(typeid(T), priority);
}

template<class T>
inline float UpdatePriorityList::GetUpdatePriority() const
{
	const auto& pair = m_priorityMap.find(typeid(T));

	if (pair == m_priorityMap.end())
	{
		return 0.0f;
	}

	return pair->second;
}

#endif // !UPDATE_PRIORITY_LIST_H_
