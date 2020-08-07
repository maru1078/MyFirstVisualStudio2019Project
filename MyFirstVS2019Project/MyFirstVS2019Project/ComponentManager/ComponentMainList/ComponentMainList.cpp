#include "ComponentMainList.h"
#include "../../Component/Component.h"

void ComponentMainList::Add(const std::shared_ptr<Component>& component)
{
    m_components.push_back(component);
}

void ComponentMainList::RemoveDeadComponent()
{
    m_components.remove_if([](const auto& component)
        {
            return component->IsDead();
        });
}

void ComponentMainList::ExecuteInput(const std::string& inputStr) const
{
    for (const auto& component : m_components)
    {
        component->Input(inputStr);
    }
}
