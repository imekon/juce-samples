#include "AppToolbarItemFactory.h"

AppToolbarItemFactory::AppToolbarItemFactory()
{

}

void AppToolbarItemFactory::getAllToolbarItemIds(Array<int> &ids)
{
	ids.add(fileNew);
	ids.add(fileOpen);
	ids.add(fileSave);
	ids.add(separatorBarId);
	ids.add(editCut);
	ids.add(editCopy);
	ids.add(editPaste);
	ids.add(separatorBarId);
	ids.add(helpAbout);
}

void AppToolbarItemFactory::getDefaultItemSet(Array<int>& ids)
{
	ids.add(fileNew);
	ids.add(fileOpen);
	ids.add(fileSave);
	ids.add(separatorBarId);
	ids.add(editCut);
	ids.add(editCopy);
	ids.add(editPaste);
	ids.add(separatorBarId);
	ids.add(helpAbout);
}

ToolbarItemComponent* AppToolbarItemFactory::createItem(int id)
{
	Drawable *image = nullptr;
	ToolbarButton *button = nullptr;

	switch (id)
	{
	case fileNew:
		image = Drawable::createFromImageData(BinaryData::new_png, BinaryData::new_pngSize);
		button = new ToolbarButton(id, "new", image, nullptr);
		break;

	case fileOpen:
		image = Drawable::createFromImageData(BinaryData::open_png, BinaryData::open_pngSize);
		button = new ToolbarButton(id, "open", image, nullptr);
		break;

	case fileSave:
		image = Drawable::createFromImageData(BinaryData::save_png, BinaryData::save_pngSize);
		button = new ToolbarButton(id, "save", image, nullptr);
		break;

	case editCut:
		image = Drawable::createFromImageData(BinaryData::cut_png, BinaryData::cut_pngSize);
		button = new ToolbarButton(id, "cut", image, nullptr);
		break;

	case editCopy:
		image = Drawable::createFromImageData(BinaryData::copy_png, BinaryData::copy_pngSize);
		button = new ToolbarButton(id, "copy", image, nullptr);
		break;

	case editPaste:
		image = Drawable::createFromImageData(BinaryData::paste_png, BinaryData::paste_pngSize);
		button = new ToolbarButton(id, "paste", image, nullptr);
		break;

	case helpAbout:
		image = Drawable::createFromImageData(BinaryData::about_png, BinaryData::about_pngSize);
		button = new ToolbarButton(id, "about", image, nullptr);
		break;
	}

	buttons[id - 1] = button;

	return button;
}