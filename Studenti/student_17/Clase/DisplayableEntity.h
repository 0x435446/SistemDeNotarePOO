#pragma once

#define RIGHT false
#define LEFT true

class DisplayableEntity
{
public:
	DisplayableEntity();
	virtual ~DisplayableEntity();
	int GetX() const;
	int GetY() const;
	int GetSpeed() const;
	bool GetMoving() const;
	bool GetDirection() const;
protected:
	void SetPosition(const int x, const int y);
	void SetSpeed(const int speed);
	void SetMoving(const bool moving);
	void SetDirection(const bool direction);
private:
	int m_x;
	int m_y;
	int m_speed;
	bool m_moving;
	bool m_direction;
};