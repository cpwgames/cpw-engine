# .desktop file
configure_file(
	project.desktop.in 
	${PROJECT_NAME}.desktop
)

# .glade file
configure_file(
	project.glade 
	${PROJECT_BINARY_DIR}/share/${PROJECT_NAME}.glade
)

# .pc file
configure_file(
	project.pc.in
	${PROJECT_NAME}.pc 
	@ONLY
)