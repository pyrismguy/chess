#pragma once

class Scene
{
    const char *title, *author;
public:
    /* the Scene class constructor can currently only parse from .xml files where the first tag is the root of the scene hierarchy.
     * Make sure your xml file is properly structured if you are having errors loading/saving scenes.
     */
    Scene(const char *file);
    virtual ~Scene()=default;

    inline const char *getTitle() const {
        return title;
    }
    inline const char *getAuthor() const {
        return author;
    }
};