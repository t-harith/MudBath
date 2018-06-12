#shader vertex
#version 330 core
layout (location = 0) in vec4 vPos;
void main()
{
gl_Position = vPos;
}

#shader fragment
#version 330 core
out vec4 color;
uniform vec4 u_Color;
void main()
{
color = u_Color;
}

