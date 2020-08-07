#ifndef TEST_OUTPUT_H_
#define TEST_OUTPUT_H_

#include "../Component/Component.h"

class TestOutput : public Component
{
public:

	explicit TestOutput(float drawPriority);

	virtual std::weak_ptr<Component> CloneComponent() const override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void OnCollide(const std::weak_ptr<GameObject>& other) override;
};

#endif // !TEST_OUTPUT_H_

