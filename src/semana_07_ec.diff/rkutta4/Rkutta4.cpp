#include <print>
#include <valarray>
#include <string>
#include <map> 

typedef std::valarray<double> state_t; 
typedef std::map<std::string, double> params_t;

void initial_conditions(state_t & s, double t0);
void print(const state_t & s, double t);
void deriv(const state_t & s, state_t & dsdt, double t, params_t & params);
template <class deriv_t, class s_t, class print_t>
void runge_kutta4(deriv_t deriv, s_t & s, double t0, double tf, double dt, params_t & params, print_t writer);

int main(void)
    {
        int N = 3;
        state_t s(N);
        params_t params;
        params["p"] = 28.0;
        params["beta"] = 8.0/3.0;
        params["sigma"] = 10.0;
        initial_conditions(s, 0);

        runge_kutta4(deriv, s, 0.0, 50.0, 0.01, params, print);
  
        return 0;
    }


void deriv(const state_t & s, state_t & dsdt, double t, params_t & params)
    {
        dsdt[0] = params["sigma"]*(s[1]-s[0]);
        dsdt[1] = s[0]*(params["p"]-s[2]) - s[1];
        dsdt[2] = s[0]*s[1] - params["beta"]*s[2];
    }

void initial_conditions(state_t & s, double t0)
    {
        s[0] = 1.9876;
        s[1] = 0.7483;
        s[2] = 2.3682;
    }

void print(const state_t & s, double t)
    {
        std::println("{:25.16e} {:25.16e} {:25.16e} {:25.16e}", t, s[0], s[1], s[2]);
    }

template <class deriv_t, class s_t, class print_t>
void runge_kutta4(deriv_t deriv, s_t & s, double t0, double tf, double dt, params_t & params, print_t writer)
    {
        state_t k1(s.size());
        state_t k2(s.size());
        state_t k3(s.size());
        state_t k4(s.size());

        writer(s, t0); //primer paso

        for(double t = t0; t <= tf; t = t + dt) //pasos subsecuentes o consecutivos al primero :D
            {
                deriv(s, k1, t, params);
                deriv(s + dt*k1/2.0, k2, t + dt/2.0, params);
                deriv(s + dt*k2/2.0, k3, t + dt/2.0, params);
                deriv(s + dt*k3, k4, t + dt, params);
                
                s = s + dt*(k1 + 2*k2 + 2*k3 + k4)/6.0;
                
                writer(s, t+dt);
            }
}