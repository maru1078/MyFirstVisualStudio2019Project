#ifndef TEST_OUTPUT_H_
#define TEST_OUTPUT_H_

#include "../Component/Component.h"

class TestOutput : public Component
{
public:

	virtual std::weak_ptr<Component> CloneComponent() override;
	virtual void Update() override;
	virtual void Draw() override;
};

#endif // !TEST_OUTPUT_H_

