
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_FontMetrics__
#define __java_awt_FontMetrics__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Font;
        class FontMetrics;
        class Graphics;
      namespace font
      {
          class FontRenderContext;
          class LineMetrics;
      }
      namespace geom
      {
          class Rectangle2D;
      }
    }
    namespace text
    {
        class CharacterIterator;
    }
  }
}

class java::awt::FontMetrics : public ::java::lang::Object
{

public: // actually protected
  FontMetrics(::java::awt::Font *);
public:
  virtual ::java::awt::Font * getFont();
  virtual jint getLeading();
  virtual jint getAscent();
  virtual jint getDescent();
  virtual jint getHeight();
  virtual jint getMaxAscent();
  virtual jint getMaxDescent();
  virtual jint getMaxDecent();
  virtual jint getMaxAdvance();
  virtual jint charWidth(jint);
  virtual jint charWidth(jchar);
  virtual jint stringWidth(::java::lang::String *);
  virtual jint charsWidth(JArray< jchar > *, jint, jint);
  virtual jint bytesWidth(JArray< jbyte > *, jint, jint);
  virtual JArray< jint > * getWidths();
  virtual ::java::lang::String * toString();
  virtual ::java::awt::font::LineMetrics * getLineMetrics(::java::lang::String *, ::java::awt::Graphics *);
  virtual ::java::awt::font::LineMetrics * getLineMetrics(::java::lang::String *, jint, jint, ::java::awt::Graphics *);
  virtual ::java::awt::font::LineMetrics * getLineMetrics(JArray< jchar > *, jint, jint, ::java::awt::Graphics *);
  virtual ::java::awt::geom::Rectangle2D * getMaxCharBounds(::java::awt::Graphics *);
  virtual ::java::awt::font::LineMetrics * getLineMetrics(::java::text::CharacterIterator *, jint, jint, ::java::awt::Graphics *);
  virtual ::java::awt::geom::Rectangle2D * getStringBounds(::java::lang::String *, ::java::awt::Graphics *);
  virtual ::java::awt::geom::Rectangle2D * getStringBounds(::java::lang::String *, jint, jint, ::java::awt::Graphics *);
  virtual ::java::awt::geom::Rectangle2D * getStringBounds(JArray< jchar > *, jint, jint, ::java::awt::Graphics *);
  virtual ::java::awt::geom::Rectangle2D * getStringBounds(::java::text::CharacterIterator *, jint, jint, ::java::awt::Graphics *);
private:
  ::java::awt::font::FontRenderContext * getFontRenderContext(::java::awt::Graphics *);
public:
  virtual jboolean hasUniformLineMetrics();
private:
  static const jlong serialVersionUID = 1681126225205050147LL;
public: // actually protected
  ::java::awt::Font * __attribute__((aligned(__alignof__( ::java::lang::Object)))) font;
private:
  static ::java::awt::font::FontRenderContext * gRC;
public:
  static ::java::lang::Class class$;
};

#endif // __java_awt_FontMetrics__
