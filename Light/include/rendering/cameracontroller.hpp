#ifndef __CAMERACONTROLLER_H__
#define __CAMERACONTROLLER_H__

#include "core/base.hpp"

#include "rendering/camera.hpp"
#include "core/timestep.hpp"
#include "events/event.hpp"
#include "events/keyevent.hpp"
#include "events/mouseevent.hpp"
#include "events/applicationevent.hpp"

namespace Light
{
	class PerspectiveCameraController
	{
	public:
		PerspectiveCameraController(float fovy, float aspectRatio, float near, float far);

		void onUpdate(Timestep ts);

		void onEvent(Event& e);

		inline void setAspectRatio(float aspectRatio)
		{ 
			this->aspectRatio = aspectRatio; 
			camera.setProjection(fovy, aspectRatio, near, far); 
		}

		inline void setPosition(glm::vec3 position) { this->position = position; camera.setPosition(position); }
		const glm::vec3& getPosition() const { return position; }

		inline void setLookAtDirection(glm::vec3 lookAtDirection) 
		{
			this->lookAtDirection = lookAtDirection;
			camera.setLookAtDirection(lookAtDirection);
		}
	
		const glm::vec3& getLookAtDirection() const { return lookAtDirection; }

		PerspectiveCamera& getCamera() { return camera; }
		const PerspectiveCamera& getCamera() const { return camera; }

	private:

		bool onMouseScrolled(MouseScrolledEvent& e);
		bool onWindowResized(WindowResizeEvent& e);
		bool onMouseButtonPressed(MouseButtonPressedEvent& e);
		bool onMouseButtonReleased(MouseButtonReleasedEvent& e);
		bool onMouseMoved(MouseMovedEvent& e);
		bool onKeyPressed(KeyPressedEvent& e);
		bool onKeyReleased(KeyReleasedEvent& e);

		float aspectRatio;
		float fovy;
		float near;
		float far;

		glm::vec3 position;
		glm::vec3 lookAtDirection;
		glm::vec3 upDirection;

		float cameraPositionSpeed;

		PerspectiveCamera camera;

		bool mousePressed;
		bool ctrlPressed;
		std::tuple<double, double> mousePos;
	};
	

}

#endif // __CAMERACONTROLLER_H__