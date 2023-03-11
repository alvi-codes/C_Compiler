#ifndef ast_bitwise_hpp
#define ast_bitwise_hpp

#include "../ast_node.hpp"
#include "ast_operator.hpp"

class AndBitwiseOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "&"; }
    public:
        AndBitwiseOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"and "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
        }
};

class OrBitwiseOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "|"; }
    public:
        OrBitwiseOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}
            virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"or "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
        }
};

class XorBitwiseOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "^"; }
    public:
        XorBitwiseOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}
            virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"xor "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
        }

};

#endif
