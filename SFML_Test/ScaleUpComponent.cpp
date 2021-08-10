#include "pch.h"
#include "ScaleUpComponent.h"

ScaleUpComponent::ScaleUpComponent(ScaleData* scaleData, TextureComponent * _textureComponent)
{
	textureComponent = _textureComponent;
	queue = new vector<ScaleData*>();
	Add(scaleData);
}

void ScaleUpComponent::Update(float dt)
{
	if (queue->size() > 0)
	{
		currentTime += dt;
		ScaleData* data = queue->at(0);

		if (currentTime < data->time)
		{
			float percentage = currentTime / data->time;
			float value = data->from + ((data->to - data->from) * percentage);
			float signedValue = textureComponent->GetScale().x < 0 ? -value : value;

			sf::Vector2f* scalen = new sf::Vector2f(signedValue, value);
			textureComponent->Scale(scalen);
		}
		else 
		{
			ScaleData* data = queue->at(0);
			float signedValue = textureComponent->GetScale().x < 0 ? -data->to : data->to;
			sf::Vector2f* scalen = new sf::Vector2f(signedValue, data->to);
			textureComponent->Scale(scalen);
			if (data->cb != nullptr) 
			{
				data->cb->Invoke();
			}
			queue->erase(queue->begin());
			currentTime = 0;
			/*if (queue->size() > 0) 
			{
				cout << queue->at(0)->ToString() << endl;
			}*/
		}
	}
}

string ScaleUpComponent::GetClassName()
{
	return "ScaleUpComponent";
}

void ScaleUpComponent::Add(ScaleData* scale)
{
	queue->push_back(scale);
}
