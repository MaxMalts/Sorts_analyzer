#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include "Include\Extra.h"
#include "Include\Common.h"
#include "Include\Application.h"
#include "Include\Primitives\Rectangle.h"



namespace GUI {

	RectangleProps::RectangleProps(const Vector2& pos, const Vector2& size, const Color& color)
		: pos(pos), size(size), color(color) {}


	Rectangle::Rectangle(OSWindow& osWindow, const RectangleProps& props)
		: Primitive(osWindow), props(props) {}


	void Rectangle::Draw() {
		GlCoordinates begPosGl =
			OSWindowToGlCoords(osWindow, props.pos);
		GlCoordinates endPosGl =
			OSWindowToGlCoords(osWindow, Vector2(props.pos.x + props.size.x, props.pos.y + props.size.y));

		osWindow.SetActive();

		glColor3f(props.color.Redness(), props.color.Greenness(), props.color.Blueness());

		glBegin(GL_QUADS);
		glVertex2f(begPosGl.x, begPosGl.y);
		glVertex2f(endPosGl.x, begPosGl.y);
		glVertex2f(endPosGl.x, endPosGl.y);
		glVertex2f(begPosGl.x, endPosGl.y);
		glEnd();
	}
}