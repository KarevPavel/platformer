//
// Created by yacopsae on 18/08/2021.
//

#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "SFML/Graphics.hpp"
#include "keyboard.h"

namespace core::keyboard {

template<class T>
class KeyboardEngine {

 protected:
  T &control;

 public:
  explicit KeyboardEngine(T &_control) : control(_control) {}

  virtual void A_click() {}

  virtual void B_click() {}

  virtual void C_click() {}

  virtual void D_click() {}

  virtual void E_click() {}

  virtual void F_click() {}

  virtual void G_click() {}

  virtual void H_click() {}

  virtual void I_click() {}

  virtual void J_click() {}

  virtual void K_click() {}

  virtual void L_click() {}

  virtual void M_click() {}

  virtual void N_click() {}

  virtual void O_click() {}

  virtual void P_click() {}

  virtual void Q_click() {}

  virtual void R_click() {}

  virtual void S_click() {}

  virtual void T_click() {}

  virtual void U_click() {}

  virtual void V_click() {}

  virtual void W_click() {}

  virtual void X_click() {}

  virtual void Y_click() {}

  virtual void Z_click() {}

  virtual void Num0_click() {}

  virtual void Num1_click() {}

  virtual void Num2_click() {}

  virtual void Num3_click() {}

  virtual void Num4_click() {}

  virtual void Num5_click() {}

  virtual void Num6_click() {}

  virtual void Num7_click() {}

  virtual void Num8_click() {}

  virtual void Num9_click() {}

  virtual void Escape_click() {}

  virtual void LControl_click() {}

  virtual void LShift_click() {}

  virtual void LAlt_click() {}

  virtual void LSystem_click() {}

  virtual void RControl_click() {}

  virtual void RShift_click() {}

  virtual void RAlt_click() {}

  virtual void RSystem_click() {}

  virtual void Menu_click() {}

  virtual void LBracket_click() {}

  virtual void RBracket_click() {}

  virtual void Semicolon_click() {}

  virtual void Comma_click() {}

  virtual void Period_click() {}

  virtual void Quote_click() {}

  virtual void Slash_click() {}

  virtual void Backslash_click() {}

  virtual void Tilde_click() {}

  virtual void Equal_click() {}

  virtual void Hyphen_click() {}

  virtual void Space_click() {}

  virtual void Enter_click() {}

  virtual void Backspace_click() {}

  virtual void Tab_click() {}

  virtual void PageUp_click() {}

  virtual void PageDown_click() {}

  virtual void End_click() {}

  virtual void Home_click() {}

  virtual void Insert_click() {}

  virtual void Delete_click() {}

  virtual void Add_click() {}

  virtual void Subtract_click() {}

  virtual void Multiply_click() {}

  virtual void Divide_click() {}

  virtual void Left_click() {}

  virtual void Right_click() {}

  virtual void Up_click() {}

  virtual void Down_click() {}

  virtual void Numpad0_click() {}

  virtual void Numpad1_click() {}

  virtual void Numpad2_click() {}

  virtual void Numpad3_click() {}

  virtual void Numpad4_click() {}

  virtual void Numpad5_click() {}

  virtual void Numpad6_click() {}

  virtual void Numpad7_click() {}

  virtual void Numpad8_click() {}

  virtual void Numpad9_click() {}

  virtual void F1_click() {}

  virtual void F2_click() {}

  virtual void F3_click() {}

  virtual void F4_click() {}

  virtual void F5_click() {}

  virtual void F6_click() {}

  virtual void F7_click() {}

  virtual void F8_click() {}

  virtual void F9_click() {}

  virtual void F10_click() {}

  virtual void F11_click() {}

  virtual void F12_click() {}

  virtual void F13_click() {}

  virtual void F14_click() {}

  virtual void F15_click() {}

  virtual void Pause_click() {}

  virtual void update(sf::Event::KeyEvent keyevent) {
	switch (keyevent.code) {
	  case sf::Keyboard::A:A_click();
		break;
	  case sf::Keyboard::B:B_click();
		break;
	  case sf::Keyboard::C:C_click();
		break;
	  case sf::Keyboard::D:D_click();
		break;
	  case sf::Keyboard::E:E_click();
		break;
	  case sf::Keyboard::F:F_click();
		break;
	  case sf::Keyboard::G:G_click();
		break;
	  case sf::Keyboard::H:H_click();
		break;
	  case sf::Keyboard::I:I_click();
		break;
	  case sf::Keyboard::J:J_click();
		break;
	  case sf::Keyboard::K:K_click();
		break;
	  case sf::Keyboard::L:L_click();
		break;
	  case sf::Keyboard::M:M_click();
		break;
	  case sf::Keyboard::N:N_click();
		break;
	  case sf::Keyboard::O:O_click();
		break;
	  case sf::Keyboard::P:P_click();
		break;
	  case sf::Keyboard::Q:Q_click();
		break;
	  case sf::Keyboard::R:R_click();
		break;
	  case sf::Keyboard::S:S_click();
		break;
	  case sf::Keyboard::T:T_click();
		break;
	  case sf::Keyboard::U:U_click();
		break;
	  case sf::Keyboard::V:V_click();
		break;
	  case sf::Keyboard::W:W_click();
		break;
	  case sf::Keyboard::X:X_click();
		break;
	  case sf::Keyboard::Y:Y_click();
		break;
	  case sf::Keyboard::Z:Z_click();
		break;
	  case sf::Keyboard::Num0:Num0_click();
		break;
	  case sf::Keyboard::Num1:Num1_click();
		break;
	  case sf::Keyboard::Num2:Num2_click();
		break;
	  case sf::Keyboard::Num3:Num3_click();
		break;
	  case sf::Keyboard::Num4:Num4_click();
		break;
	  case sf::Keyboard::Num5:Num5_click();
		break;
	  case sf::Keyboard::Num6:Num6_click();
		break;
	  case sf::Keyboard::Num7:Num7_click();
		break;
	  case sf::Keyboard::Num8:Num8_click();
		break;
	  case sf::Keyboard::Num9:Num9_click();
		break;
	  case sf::Keyboard::Escape:Escape_click();
		break;
	  case sf::Keyboard::LControl:LControl_click();
		break;
	  case sf::Keyboard::LShift:LShift_click();
		break;
	  case sf::Keyboard::LAlt:LAlt_click();
		break;
	  case sf::Keyboard::LSystem:LSystem_click();
		break;
	  case sf::Keyboard::RControl:RControl_click();
		break;
	  case sf::Keyboard::RShift:RShift_click();
		break;
	  case sf::Keyboard::RAlt:RAlt_click();
		break;
	  case sf::Keyboard::RSystem:RSystem_click();
		break;
	  case sf::Keyboard::Menu:Menu_click();
		break;
	  case sf::Keyboard::LBracket:LBracket_click();
		break;
	  case sf::Keyboard::RBracket:RBracket_click();
		break;
	  case sf::Keyboard::Semicolon:Semicolon_click();
		break;
	  case sf::Keyboard::Comma:Comma_click();
		break;
	  case sf::Keyboard::Period:Period_click();
		break;
	  case sf::Keyboard::Quote:Quote_click();
		break;
	  case sf::Keyboard::Slash:Slash_click();
		break;
	  case sf::Keyboard::Backslash:Backslash_click();
		break;
	  case sf::Keyboard::Tilde:Tilde_click();
		break;
	  case sf::Keyboard::Equal:Equal_click();
		break;
	  case sf::Keyboard::Hyphen:Hyphen_click();
		break;
	  case sf::Keyboard::Space:Space_click();
		break;
	  case sf::Keyboard::Enter:Enter_click();
		break;
	  case sf::Keyboard::Backspace:Backspace_click();
		break;
	  case sf::Keyboard::Tab:Tab_click();
		break;
	  case sf::Keyboard::PageUp:PageUp_click();
		break;
	  case sf::Keyboard::PageDown:PageDown_click();
		break;
	  case sf::Keyboard::End:End_click();
		break;
	  case sf::Keyboard::Home:Home_click();
		break;
	  case sf::Keyboard::Insert:Insert_click();
		break;
	  case sf::Keyboard::Delete:Delete_click();
		break;
	  case sf::Keyboard::Add:Add_click();
		break;
	  case sf::Keyboard::Subtract:Subtract_click();
		break;
	  case sf::Keyboard::Multiply:Multiply_click();
		break;
	  case sf::Keyboard::Divide:Divide_click();
		break;
	  case sf::Keyboard::Left:Left_click();
		break;
	  case sf::Keyboard::Right:Right_click();
		break;
	  case sf::Keyboard::Up:Up_click();
		break;
	  case sf::Keyboard::Down:Down_click();
		break;
	  case sf::Keyboard::Numpad0:Numpad0_click();
		break;
	  case sf::Keyboard::Numpad1:Numpad1_click();
		break;
	  case sf::Keyboard::Numpad2:Numpad2_click();
		break;
	  case sf::Keyboard::Numpad3:Numpad3_click();
		break;
	  case sf::Keyboard::Numpad4:Numpad4_click();
		break;
	  case sf::Keyboard::Numpad5:Numpad5_click();
		break;
	  case sf::Keyboard::Numpad6:Numpad6_click();
		break;
	  case sf::Keyboard::Numpad7:Numpad7_click();
		break;
	  case sf::Keyboard::Numpad8:Numpad8_click();
		break;
	  case sf::Keyboard::Numpad9:Numpad9_click();
		break;
	  case sf::Keyboard::F1:F1_click();
		break;
	  case sf::Keyboard::F2:F2_click();
		break;
	  case sf::Keyboard::F3:F3_click();
		break;
	  case sf::Keyboard::F4:F4_click();
		break;
	  case sf::Keyboard::F5:F5_click();
		break;
	  case sf::Keyboard::F6:F6_click();
		break;
	  case sf::Keyboard::F7:F7_click();
		break;
	  case sf::Keyboard::F8:F8_click();
		break;
	  case sf::Keyboard::F9:F9_click();
		break;
	  case sf::Keyboard::F10:F10_click();
		break;
	  case sf::Keyboard::F11:F11_click();
		break;
	  case sf::Keyboard::F12:F12_click();
		break;
	  case sf::Keyboard::F13:F13_click();
		break;
	  case sf::Keyboard::F14:F14_click();
		break;
	  case sf::Keyboard::F15:F15_click();
		break;
	  case sf::Keyboard::Pause:Pause_click();
		break;

	  default:break;
	}
  };
};
}